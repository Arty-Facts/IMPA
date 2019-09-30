#python3 
from collections import defaultdict
import sys

def main():
    while True:
        lines = int(sys.stdin.readline().strip())
        freq = defaultdict(int)
        if lines == 0:
            break
        for i in range(lines):
            team = tuple(sorted(map(int,sys.stdin.readline().split())))
            freq[team] += 1
        corses = sorted(freq.items(), key=lambda x:x[1], reverse=True) 
        popularity = 0
        for _, p in corses:
            if p != corses[0][1]:
                break
            popularity += p
        print(popularity)

        

if __name__ == "__main__":
    main()
