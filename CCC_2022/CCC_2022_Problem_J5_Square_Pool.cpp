#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, t, ans = 0;
    cin >> n >> t;
    if(t == 0){
        cout << n << endl;
        return 0;
    }
    vector<pair<int, int>> tree;
    tree.push_back({0, 0});
    for(int i=0, a, b; i<t; i++){
        cin >> a >> b;
        tree.push_back({a, b});
    }
    for(pair<int, int> pi: tree){
        int top = pi.first;
        for(pair<int, int> pj: tree){
            int left = pj.second;
            int sz = min(n-top, n-left);
            for(pair<int, int> pk: tree){
                if(pk.first > top && pk.second > left){
                    sz = min(sz, max(pk.first-top-1, pk.second-left-1));
                }
            }
            ans = max(ans, sz);
        }
    }
    cout << ans << endl;
    return 0;
}
