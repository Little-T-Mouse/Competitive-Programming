#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int N; scanf("%d", &N);
    for(int i=0; i<=N; i++){
        if((N-i)%4==0 && i%5==0){
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
