def NC3(x):
    return x*(x-1)*(x-2)//6

N, C = map(int, input().split())
p = list(map(int, input().split()))
freq = [0]*C
psa = [0]*(2*C+2)
for i in p:
    freq[i] += 1
for i in range(1, 2*C+1):
    psa[i] = psa[i-1] + freq[(i-1)%C]
ans = NC3(N)
if C%2==0:
    for i in range(C//2):
        ans += NC3(freq[i]+freq[i+C//2]) - NC3(freq[i]) - NC3(freq[i+C//2])
for i in range(1, C+1):
    ans -= NC3(psa[i+C//2] - psa[i-1])-NC3(psa[i+C//2] - psa[i])
print(ans)
