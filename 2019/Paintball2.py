import sys

def mark_danger_zone(field, x, y, r, viseted):
    frontear = []
    # put(Cost, CurrentNode)
    frontear.append((x, y))
    while len(frontear) > 0:
        xi, yi = frontear.pop()
        dx = x - xi
        dy = y - yi
        if dx**2+dy**2 >= r**2 or field[xi][yi]**2 > dx**2+dy**2:
            continue
        field[xi][yi] = min(dx**2+dy**2 - r**2, field[xi][yi])
        expand(frontear, field, xi, yi)

def safe_path_exists(field, players):
    c=1
    for start_y in range(len(field)):
        if not in_reach(0, start_y, players): 
            dfs(field, 0, start_y, c, players)
            c += 1
    for end_y in range(len(field)-1, -1, -1):
        if field[len(field)-1][end_y] > 0:
            find_time = field[len(field)-1][end_y]
            for start_y in range(len(field)-1, -1, -1):
                if find_time == field[0][start_y]:
                    return 0, start_y, len(field)-1,  end_y
    return -1, -1, -1, -1

def dfs(field, x, y, viseted, players):
    frontear = []
    # put(Cost, CurrentNode)
    frontear.append((x, y))

    while len(frontear) > 0:
        xi, yi = frontear.pop(-1)
        if field[xi][yi] > 0:
            continue
        field[xi][yi] = viseted

        expand(frontear, field, xi, yi, players)

def expand(frontear, field, x, y, players):
    for dx, dy in [(0,1),(0,-1),(-1,0),(1,0)]:
        if valid(field, x+dx, y+dy) and field[x+dx][y+dy] == 0 and not in_reach(x+dx, y+dy, players):
            frontear.append((x+dx, y+dy))
    
def in_reach(x,y, players):
    for px, py, r in players:
        if (px-x)**2 + (py-y)**2 < r**2:
            return True
    return False 

def valid(field, x, y):
    return 0 <= x and x < len(field) and 0 <= y and  y < len(field)

def main():
    size = 1001
    _ = sys.stdin.readline() 
    field = [ [0]*size for _ in range(size)]
    players = []
    for i, line in enumerate(sys.stdin.readlines()):
        x, y, r = map(int, line.split())
        players.append((x, y, r))
        #mark_danger_zone(field, x, y, r, -(i+1))
    x_s, y_s, x_e, y_e = safe_path_exists(field, players)
    # for f in field:
    #     for t in f:
    #         print(t, end=" ")
    #     print()
    if y_s != -1:
        print(f"{x_s:.2f} {y_s:.2f} {x_e:.2f} {y_e:.2f}")
    else:
        print("IMPOSSIBLE")


if __name__ == "__main__":
    main()