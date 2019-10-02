#python3 
import sys
ans = ""
def main():
    N , R = map(int,sys.stdin.readline().split())
    data  = {}
    for i in range(N):
        name, *info = sys.stdin.readline().split()
        data[name] = list(map(int,info))
    for k,v in data.items():
        print(k,v)
        

if __name__ == "__main__":
    main()

