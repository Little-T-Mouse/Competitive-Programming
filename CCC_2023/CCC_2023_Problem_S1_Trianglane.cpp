// Problem J4/S1: Trianglane
#include <bits/stdc++.h>
using namespace std;
const int MC = 2e5+5;
int C, grid[3][MC], ans;

int main() {
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> C;
    for(int i=1; i<=2; i++) {
        for(int j=1; j<=C; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 1) ans += 3;
        }
    }
    for(int i=1; i<=2; i++) {
        for(int j=1; j<=C; j++) {
            if(j % 2 == 1 && grid[i][j] == 1 && grid[i-1][j] == 1) ans -= 2;
            if(grid[i][j] == 1 && grid[i][j-1] == 1) ans -= 2;
        }
    }
    cout << ans << "\n";
    return 0;
}
