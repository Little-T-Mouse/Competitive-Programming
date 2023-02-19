import sys
N, M, K = map(int, input().split())
if K < N or K > (N-M)*M+(1+M)*M/2:
    print(-1)
    sys.exit()
a = [0]*N
cur = a[0] = 1
K-=1
for i in range(1, N):
    if K-cur>N-i-1 and a[i-1]+1<=M:
        a[i] = a[i-1]+1
        if cur<M:
           cur+=1
        K -= cur
    else:
        while K-cur<N-i-1:
            cur-=1;
        a[i] = a[i-cur]
        K -= cur
print(*a)
