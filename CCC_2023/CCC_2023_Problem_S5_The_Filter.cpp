// CCC '23 S5 - The Filter
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, lv, prv = -1, pw3[21] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467};
vector<pair<ll, ll>> bound;

void valid(ll l, ll r, ll lvl) {
    if(r - l < 3) bound.push_back({l, r});
    else { valid(l, l + pw3[lvl - 1], lvl - 1); valid(r - pw3[lvl - 1], r, lvl - 1); }
}

bool check(ll num) {
    unordered_set<ll> st;
    while(num) {
        num *= 3;
        if(num / N == 1 && num % N != 0) return false;
        num %= N;
        if(st.count(num)) break;
        st.insert(num);
    }
    return true;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N; lv = log2(N) / log2(3);
    valid(0, pw3[lv], lv);
    for(auto[l, r]: bound) {
        for(ll i=(l*N)/pw3[lv]; i<=(r*N)/pw3[lv]; i++) {
            if(prv == i || !check(i)) continue;
            cout << i << "\n"; prv = i;
        }
    }
    return 0;
}
