// CCC '23 J2 - Chili Peppers
#include <bits/stdc++.h>
using namespace std;
int N; long long T; string s;

int main() {
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> s;
        if(s == "Poblano") T += 1500;
        else if(s == "Mirasol") T += 6000;
        else if(s == "Serrano") T += 15500;
        else if(s == "Cayenne") T += 40000;
        else if(s == "Thai") T += 75000;
        else if(s == "Habanero") T += 125000;
    }
    cout << T << "\n";
    return 0;
}
