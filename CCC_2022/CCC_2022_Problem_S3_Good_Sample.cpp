#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long N, M, K; cin >> N >> M >> K;
    if(K < N || K > (N-M)*M+(1+M)*M/2){
        cout << -1 << endl;
        return 0;
    }
    long long need = K;
    long long a[N], cur=1;
    a[0] = 1; need--;
    for(int i=1; i<N; i++){
        if(need-cur>N-i-1 && a[i-1]+1<=M){
            a[i] = a[i-1]+1;
            if(cur<M) cur++;
            need -= cur;
        }
        else{
            while(need-cur<N-i-1) cur--;
            a[i] = a[i-cur];
            need -= cur;
        }
    }
    for(int i=0; i<N; i++){
        cout << a[i] << (i==N?"\n":" ");
    }
    return 0;
}
