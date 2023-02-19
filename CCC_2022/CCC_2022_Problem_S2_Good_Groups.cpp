#include <bits/stdc++.h>
using namespace std;
int group[5000005];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int x; cin >> x; int cnt = 0;
    vector<pair<int, int>> same;
    map<string, int> name;
    for(int i=0; i<x; i++){
        string a, b; cin >> a >> b;
        if(name.count(a) == 0){
            name[a] = cnt; cnt++;
        }
        if(name.count(b) == 0){
            name[b] = cnt; cnt++;
        }
        same.push_back({name[a], name[b]});
    }
    int y; cin >> y;
    vector<pair<int, int>> dif;
    for(int i=0; i<y; i++){
        string a, b; cin >> a >> b;
        if(name.count(a) == 0){
            name[a] = cnt; cnt++;
        }
        if(name.count(b) == 0){
            name[b] = cnt; cnt++;
        }
        dif.push_back({name[a], name[b]});
    }
    int ans = 0;
    int n; cin >> n;
    for(int i=0; i<n; i++){
        string a, b, c; cin >> a >> b >> c;
        if(name.count(a) == 0){
            name[a] = cnt; cnt++;
        }
        if(name.count(b) == 0){
            name[b] = cnt; cnt++;
        }
        if(name.count(c) == 0){
            name[c] = cnt; cnt++;
        }
        group[name[a]] = group[name[b]] = group[name[c]] = i;
    }
    for(pair<int, int> pi: same){
        if(group[pi.first] != group[pi.second]) ans++;
    }
    for(pair<int, int> pi: dif){
        if(group[pi.first] == group[pi.second]) ans++;
    }
    cout << ans << endl;
    return 0;
}
