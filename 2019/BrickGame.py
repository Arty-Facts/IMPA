#python3 
import sys
ans = ""
def main():
    tests = int(sys.stdin.readline().strip())
    for i in range(tests):
        num ,*team = map(int,sys.stdin.readline().split())
        print(f'Case {i+1}: {team[num//2]}')

        

if __name__ == "__main__":
    main()
