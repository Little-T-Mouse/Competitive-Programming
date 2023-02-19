// CCC '23 J3 - Special Event
#include <bits/stdc++.h>
using namespace std;
int N, amt[6]; char ch; vector<pair<int, int>> stat; vector<int> ans;

int main() {
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=5; j++) {
            cin >> ch;
            amt[j] += (ch == 'Y');
        }
    }
    for(int i=1; i<=5; i++) stat.push_back({amt[i], i});
    sort(stat.begin(), stat.end(), greater<pair<int, int>>());
    ans.push_back(stat[0].second);
    for(int i=1; i<5; i++) {
        if(stat[i].first != stat[i-1].first) break;
        ans.push_back(stat[i].second);
    }
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++) cout << ans[i] << ",\n"[i==ans.size()-1];
    return 0;
}
