N = int(input())
cnt = 0
for i in range(N+1):
    if (N-i) % 4 == 0 and i % 5 == 0:
        cnt += 1
print(cnt)
