#python3 
from collections import defaultdict
from queue import PriorityQueue
import sys

def find(N, S, Path, Stores):
    frontear = PriorityQueue()
    viseted = [False]*N
    return_q = [False]*N
    # put(Cost, CurrentNode, S:s)
    frontear.put((0, 0, 0))
    while not frontear.empty():
        cost, curr_node, stores = frontear.get()
        #print(cost)
        if stores >= S and curr_node == 0:
            return cost
        if viseted[curr_node]:
            if stores >= S and not return_q[curr_node]:
                return_q[curr_node] = True
                expand(Path, Stores, frontear, return_q, curr_node, cost, stores, N)
        else:
            viseted[curr_node] = True
            expand(Path, Stores, frontear, viseted, curr_node, cost, stores, N)
            
def expand(Path, Stores, frontear, viseted, curr_node, cost, stores, N):
    for next_node in range(N):
        d = Path[curr_node][next_node]
        if d != -1 and not viseted[next_node]:
            if Stores[next_node]:
                stores += 1
            frontear.put((cost+d, next_node, stores))

def main():
    tests = int(sys.stdin.readline().strip())
    for i in range(tests):
        N, M = map(int,sys.stdin.readline().split())
        Path = [[-1] * N for i in range(N)]
        Stores = [False]*N
        # Read paths
        for i in range(M):
            x, y, d = map(int,sys.stdin.readline().split())
            Path[x][y] = d
            Path[y][x] = d

        # for p in Path:
        #     for t in p:
        #         print(t, end=" ")
        #     print()
        S = int(sys.stdin.readline().strip())
        for i in range(S):
            s = int(sys.stdin.readline().strip())
            Stores[s] = True
            
        print(find(N, S, Path, Stores))


        

if __name__ == "__main__":
    main()
