// CCC '23 J5 - CCC Word Hunt
#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int, int> pi;
const int MN = 102;
string word; int R, C; char grid[MN][MN]; set<vector<pi>> ans;
int dir[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
map<pi, vector<pi>> mp;

void dfs(int x, int y, int dx, int dy, int turn, string cur, vector<pi> step) {
    if(x < 1 || y < 1 || x > R || y > C || turn > 1 || cur.size() > word.size()) return;
    if(cur == word) { ans.insert(step); return; }
    step.push_back({x + dx, y + dy});
    dfs(x + dx, y + dy, dx, dy, turn, cur + grid[x + dx][y + dy], step);
    int ddx = mp[{dx, dy}][0].f, ddy = mp[{dx, dy}][0].s;
    step.pop_back(); step.push_back({x + ddx, y + ddy});
    dfs(x + ddx, y + ddy, ddx, ddy, turn + 1, cur + grid[x + ddx][y + ddy], step);
    ddx = mp[{dx, dy}][1].f, ddy = mp[{dx, dy}][1].s;
    step.pop_back(); step.push_back({x + ddx, y + ddy});
    dfs(x + ddx, y + ddy, ddx, ddy, turn + 1, cur + grid[x + ddx][y + ddy], step);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mp[{1, 1}] = {{1, -1}, {-1, 1}};
    mp[{-1, -1}] = {{1, -1}, {-1, 1}};
    mp[{1, -1}] = {{-1, -1}, {1, 1}};
    mp[{-1, 1}] = {{-1, -1}, {1, 1}};
    mp[{0, 1}] = {{-1, 0}, {1, 0}};
    mp[{0, -1}] = {{-1, 0}, {1, 0}};
    mp[{1, 0}] = {{0, -1}, {0, 1}};
    mp[{-1, 0}] = {{0, -1}, {0, 1}};
    cin >> word >> R >> C;
    for(int r=1; r<=R; r++)
        for(int c=1; c<=C; c++)
            cin >> grid[r][c];
    for(int r=1; r<=R; r++)
        for(int c=1; c<=C; c++)
            for(int d=0; d<8; d++)
                dfs(r, c, dir[d][0], dir[d][1], 0, string(1, grid[r][c]), {(pi){r, c}});
    cout << ans.size() << "\n";
    return 0;
}
