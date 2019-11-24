#python3 
import sys

def main():
    tests = int(sys.stdin.readline().strip())
    for _ in range(tests):
        K = int(sys.stdin.readline().strip())
        vocab = {}
        tot = 0
        for _ in range(K):
            k , cent = sys.stdin.readline().split()
            vocab[k] = int(cent)
        M = int(sys.stdin.readline().strip())
        for _ in range(M):
            line = sys.stdin.readline().strip()
            for c in line:
                if c in vocab:
                    tot += vocab[c]
        print(f"{tot/100:.2f}$")



        

if __name__ == "__main__":
    main()
