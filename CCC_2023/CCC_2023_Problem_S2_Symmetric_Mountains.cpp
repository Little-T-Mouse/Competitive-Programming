// Problem S2: Symmetric Mountains
#include <bits/stdc++.h>
using namespace std;
const int MN = 1e5+5;
int N, h[MN], ans[MN];

int main() {
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N; memset(ans, 0x3f, sizeof ans);
    for(int i=1; i<=N; i++) cin >> h[i];
    for(int mid=1; mid<=N; mid++) {
        int sum = 0;
        for(int dx=0; dx<mid; dx++) {
            if(mid - dx < 1 || mid + dx > N) break;
            sum += abs(h[mid - dx] - h[mid + dx]);
            ans[2*dx+1] = min(ans[2*dx+1], sum);
        }
        sum = 0;
        for(int dx=0; dx<mid; dx++) {
            if(mid - dx < 1 || mid + dx + 1 > N) break;
            sum += abs(h[mid - dx] - h[mid + dx + 1]);
            ans[2*dx+2] = min(ans[2*dx+2], sum);
        }
    }
    for(int i=1; i<=N; i++) cout << ans[i] << " \n"[i==N];
    return 0;
}
