import sys
sys.setrecursionlimit(100000000)
graph = [[] for i in range(200005)]
want = [0]*200005
dp = [[[0 for k in range(2)] for j in range(2)] for i in range(200005)]
tmpdp = [[0 for j in range(2)] for i in range(2)]
N = int(input())
for i in range(N-1):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
s = input()
for i in range(N):
    want[i+1] = (s[i] == 'Y')
cost = [0]+list(map(int, input().split()))

def dfs(cur, pre):
    dp[cur][0][0] = 0
    dp[cur][0][1] = cost[cur]
    if want[cur]:
        dp[cur][1][0] = 0
        dp[cur][1][1] = cost[cur]
    else:
        dp[cur][1][0] = dp[cur][1][1] = 123456789101112
    for nxt in graph[cur]:
        if nxt == pre:
            continue
        dfs(nxt, cur)
        for i in range(2):
            for j in range(2):
                tmpdp[i][j] = 123456789101112
        for i in range(2):
            for j in range(2):
                for m in range(2):
                    for n in range(2):
                        if not j and not m:
                            continue
                        p = i|(m&n)
                        q = j
                        tmpdp[p][q] = min(tmpdp[p][q], dp[cur][i][j] + dp[nxt][m][n]);
        for i in range(2):
            for j in range(2):
                dp[cur][i][j] = tmpdp[i][j]
dfs(1, 0)
print(min(dp[1][1][0], dp[1][1][1]))
