import sys

X = int(sys.stdin.readline())
N = int(sys.stdin.readline())
#print(X,N)
megsUsed = 0
for i in range(N):
    P = int(sys.stdin.readline())
    megsUsed = megsUsed + P

print((N+1)*X - megsUsed)


