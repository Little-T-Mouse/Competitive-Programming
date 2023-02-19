#include <bits/stdc++.h>
using namespace std;
// Total num of triangles - invalid triangles
typedef long long ll;
const int MN = 1e6+6;
ll N, C, freq[MN], psa[2*MN];
ll NC3(ll x) {return x*(x-1)*(x-2)/6;}
int main(){
    cin >> N >> C;
    ll ans = NC3(N);
    for(int i=0, x; i<N; i++) {
        cin >> x; freq[x]++;
    }
    for(int i=1; i<=2*C; i++){
        psa[i] = psa[i-1] + freq[(i-1)%C];
    }
    if(C%2==0){ // add the part that over subtract
        for(int i=0; i<C/2; i++){
            ans += NC3(freq[i]+freq[i+C/2])-NC3(freq[i])-NC3(freq[i+C/2]);
        }
    }
    for(int i=1; i<=C; i++) {
        ans -= NC3(psa[i+C/2]-psa[i-1])-NC3(psa[i+C/2]-psa[i]);
    }
    cout << ans << endl;
}
