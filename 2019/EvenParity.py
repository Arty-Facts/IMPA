#python3 
import sys
from collections import deque

def print2d(iterable):
    for i in iterable:
        for c in i:
            print(c, end=" ")
        print()

def solve():
    pass

def main():
    tests = int(sys.stdin.readline().strip())
    for _ in range(tests):
        size = int(sys.stdin.readline().strip())
        board = []
        for _ in range(size):
            board.append(list(map(int,sys.stdin.readline().split())))

        frontear = deque()
        
        # append(Cost, CurrentNode, Stores)
        frontear.append(None)

        while not frontear.empty():
            node = frontear.pop()

            for x in range(size):
                for y in range(size):
                    frontear.append(None)
                    
        print2d(board)


        

if __name__ == "__main__":
    main()
