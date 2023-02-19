#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5+5;
int dp[MAX][2][2], tmpdp[2][2], cost[MAX]; vector<int>graph[MAX]; bool want[MAX];

void dfs(int cur, int pre){
    dp[cur][0][0] = 0;
    dp[cur][0][1] = cost[cur];
    dp[cur][1][0] = want[cur]?0:0x3f3f3f3f;
    dp[cur][1][1] = want[cur]?cost[cur]:0x3f3f3f3f;
    for(int nxt: graph[cur]){
        if(nxt == pre) continue;
        dfs(nxt, cur);
        memset(tmpdp, 0x3f, sizeof tmpdp);
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                for(int m=0; m<2; m++){
                    for(int n=0; n<2; n++){
                        if(!j && !m) continue; // not pay cur and nxt doesn't want to write
                        int p = i|(m&n); // want to or not want to
                        int q = j; // pay or not pay
                        tmpdp[p][q] = min(tmpdp[p][q], dp[cur][i][j] + dp[nxt][m][n]);
                    }
                }
            }
        }
        memcpy(dp[cur], tmpdp, sizeof tmpdp);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    // dp[node][want/not want][give money/not give money] = min cost
    int N; cin >> N;
    for(int i=1, a, b; i<N; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    string s; cin >> s;
    for(int i=1; i<=N; i++){
        want[i] = s[i-1] == 'Y';
        cin >> cost[i];
    }
    dfs(1, 0);
    cout << min(dp[1][1][0], dp[1][1][1]) << endl;
    return 0;
}
