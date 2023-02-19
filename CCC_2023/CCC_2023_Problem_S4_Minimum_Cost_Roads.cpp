// Problem S4: Minimum Cost Roads
#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair<ll, pair<int, int>> pi;
typedef pair<ll, int> p;
struct E { int u, v, id; ll l, c; };
const int MN = 2e3+3;
int N, M; ll ans, dis[MN][MN], tmp[MN]; bool keep[MN]; vector<E> edges; vector<pi> graph[MN];

bool cmp(E a, E b) { return a.c > b.c; }

int main() {
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=1, u, v; i<=M; i++) {
        ll l, c; keep[i] = true;
        cin >> u >> v >> l >> c; ans += c;
        graph[u].push_back({l, {v, i}});
        graph[v].push_back({l, {u, i}});
        edges.push_back({u, v, i, l, c});
    }
    sort(edges.begin(), edges.end(), cmp);
    memset(dis, 0x3f3f, sizeof dis);
    for(int i=1; i<=N; i++) {
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, i}); dis[i][i] = 0;
        while(!pq.empty()) {
            auto[curw, cur] = pq.top(); pq.pop();
            for(pi nxt: graph[cur]) {
                if(keep[nxt.s.s] && dis[i][nxt.s.f] > dis[i][cur] + nxt.f) {
                    dis[i][nxt.s.f] = dis[i][cur] + nxt.f;
                    pq.push({dis[i][nxt.s.f], nxt.s.f});
                }
            }
        }
    }
    for(auto[u, v, id, l, c]: edges) {
        priority_queue<p, vector<p>, greater<p>> pq;
        memset(tmp, 0x3f3f, sizeof tmp);
        pq.push({0, u}); tmp[u] = 0; keep[id] = false;
        while(!pq.empty()) {
            auto[curw, cur] = pq.top(); pq.pop();
            for(pi nxt: graph[cur]) {
                if(keep[nxt.s.s] && tmp[nxt.s.f] > tmp[cur] + nxt.f) {
                    tmp[nxt.s.f] = tmp[cur] + nxt.f;
                    pq.push({tmp[nxt.s.f], nxt.s.f});
                }
            }
        }
        if(tmp[v] == dis[u][v]) ans -= c;
        else keep[id] = true;
    }
    cout << ans << "\n";
    return 0;
}
