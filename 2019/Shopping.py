#python3 
from collections import defaultdict
from queue import PriorityQueue
import sys


def findCosts(N, S, Path, Stores, Costs, start):
    frontear = PriorityQueue()
    viseted = [False]*N
    # put(Cost, CurrentNode)
    frontear.put((0, start, 0))

    while not frontear.empty():
        cost, curr_node, stores = frontear.get()
        #print(cost)
        if viseted[curr_node]:
            continue

        if Stores[curr_node] != -1:
            stores += 1
            Costs[start][curr_node] = cost
            Costs[curr_node][start] = cost

        if stores >= S+1:
            return
            
        viseted[curr_node] = True
        expand(Path, frontear, viseted, curr_node, cost, stores, N)

def MST(N, S, Costs, Stores):
    pass
    # frontear = PriorityQueue()
    # viseted = [False]*N
    # # put(Cost, CurrentNode, Stores)
    # frontear.put((0, 0, 0))

    # while not frontear.empty():
    #     cost, curr_node, stores = frontear.get()

    #     if stores == S+1:
    #         return cost
    #     if viseted[curr_node]:
    #         continue

    #     viseted[curr_node] = True

    #     for next_node in Stores:
    #         print(curr_node, next_node, ":", stores)
    #         #print2d(Path)
    #         d = Costs[curr_node][next_node]
    #         if d > 0 and not viseted[next_node]:
    #             print("Search")
    #             frontear.put((cost+d, next_node, stores+1))
    #         elif d > 0 and stores == S and next_node == 0:
    #             print("Home")
    #             frontear.put((cost+d, next_node, stores+1))

                
def expand(Path,  frontear, viseted, curr_node, cost, stores, N):
    for next_node in range(N):
        #print(curr_node, next_node)
        #print2d(Path)
        d = Path[curr_node][next_node]
        if d != -1 and not viseted[next_node]:
            frontear.put((cost+d, next_node, stores))

def print2d(iterable):
    for i in iterable:
        for c in i:
            print(c, end=" ")
        print()

def all(iterable, comp):
    for element in iterable:
        if not comp(element):
            return False
    return True

def main():
    tests = int(sys.stdin.readline().strip())
    for i in range(tests):
        N, M = map(int,sys.stdin.readline().split())
        Path = [[-1] * N for i in range(N)]
        Stores = [-1]*N
        # Read paths
        for i in range(M):
            x, y, d = map(int,sys.stdin.readline().split())
            Path[x][y] = d
            Path[y][x] = d

        #print2d(Path)
        S = int(sys.stdin.readline().strip())
        for i in range(S):
            s = int(sys.stdin.readline().strip())
            Stores[s] = i+1
        Stores[0] = 0
        #costs from every store to vevry other and home
        Costs = [[-1] * N for i in range(N)]
        for j in range(S):
            findCosts(N, S, Path, Stores, Costs, j)
        
        print2d(Costs)
        print(MST(N, S, Costs, Stores))


        

if __name__ == "__main__":
    main()
