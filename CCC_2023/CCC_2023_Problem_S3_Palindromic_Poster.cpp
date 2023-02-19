// CCC '23 S3 - Palindromic Poster
#include <bits/stdc++.h>
using namespace std;
const int MN = 2e3+3;
int N, M, R, C; char ans[MN][MN]; bool good[MN][MN];

int main() {
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> R >> C;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            if(i <= R || j <= C) ans[i][j] = 'a';
            else ans[i][j] = (char)((i + j) % 25 + 'b');
        }
    }
    if(R == 0 && C == M) {
        for(int i=1; i<=N; i++) ans[i][1] = 'b';
    }
    else if(R == N && C == 0) {
        for(int i=1; i<=M; i++) ans[1][i] = 'b';
    }
    else if(R != 0 && C == M) {
        if((M % 2 == 0 && C % 2 == 1) || (N % 2 == 0 && R % 2 == 1)) { cout << "IMPOSSIBLE\n"; return 0; }
        for(int i=1; i<=N; i++) ans[i][1] = 'b';
        if(R % 2 == 1) ans[(N + 1) / 2][1] = 'a';
        int dx = R / 2;
        for(int i=1; i<=dx; i++) {
            ans[i][1] = 'a';
            ans[N - i + 1][1] = 'a';
        }
    }
    else if(R == N && C != 0) {
        if((M % 2 == 0 && C % 2 == 1) || (N % 2 == 0 && R % 2 == 1)) { cout << "IMPOSSIBLE\n"; return 0; }
        for(int i=1; i<=M; i++) ans[1][i] = 'b';
        if(C % 2 == 1) ans[1][(M + 1) / 2] = 'a';
        int dx = C / 2;
        for(int i=1; i<=dx; i++) {
            ans[1][i] = 'a';
            ans[1][M - i + 1] = 'a';
        }
    }
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            cout << ans[i][j] << (j == M ? "\n" : "");
    return 0;
}
