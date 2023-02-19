// CCC '23 J1 - Deliv-e-droid
#include <bits/stdc++.h>
using namespace std;
int P, C;

int main() {
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> P >> C;
    cout << 50 * P - 10 * C + (P > C ? 500 : 0) << "\n";
    return 0;
}
