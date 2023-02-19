#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, tmp = "";
    cin >> s;
    for(int i=0; i<s.size(); i++){
        if(tmp.size()!=0 && !isdigit(s[i]) && isdigit(s[i-1])){
            cout << tmp << endl;
            tmp = "";
        }
        if(isupper(s[i]) || isdigit(s[i])){
            tmp += s[i];
        }
        else if(s[i] == '-'){
            tmp += " loosen ";
        }
        else if(s[i] == '+'){
            tmp += " tighten ";
        }
    }
    cout << tmp << endl;
    return 0;
}
