n = int(input())
t = int(input())
x = [0]
y = [0]
for i in range(t):
    a, b = map(int, input().split())
    x.append(a)
    y.append(b)
ans = 0
if t == 0:
    print(n)
else:
    for top in x:
        for left in y:
            sz = min(n-top, n-left)
            for i in range(t+1):
                if x[i] > top and y[i] > left:
                    sz = min(sz, max(x[i]-top-1, y[i]-left-1))
            ans = max(ans, sz)
    print(ans)
