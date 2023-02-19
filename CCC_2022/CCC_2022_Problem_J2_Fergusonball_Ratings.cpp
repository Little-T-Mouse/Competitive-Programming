#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, cnt = 0;
    cin >> N;
    for(int i=0, a, b; i<N; i++){
        cin >> a >> b;
        if(a*5 - b*3 > 40) cnt++;
    }
    if(cnt == N) cout << cnt << "+" << endl;
    else cout << cnt << endl;
    return 0;
}
