import sys 
n = int(sys.stdin.readline())
for _ in range(n):
    b, p = map(float, sys.stdin.readline().split())
    print("{:.4f} {:.4f} {:.4f}".format(60*(b-1)/p, 60*b/p, 60*(b+1)/p)) 