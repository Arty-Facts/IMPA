#python3 
import sys
import math

def main():
    first = False
    while(True):
        N = sys.stdin.readline().strip()
        if N == "":
            return
        N = int(N)
        deth = {}
        names = [n.strip() for n in sys.stdin.readline().split()]
        for name in names:
            deth[name] = 0
        for _ in range(N):
            name, money, num, *friends = sys.stdin.readline().split()
            if num == "0":
                continue
            deth[name.strip()] -= int(money)
            deth[name.strip()] += int(money)%int(num)  
            for f in friends:
                deth[f.strip()] += int(money)//int(num)

        if first:
            print()
        first = True

        for name in names:
            print(f"{name} {deth[name]}")
        
            



        

if __name__ == "__main__":
    main()
