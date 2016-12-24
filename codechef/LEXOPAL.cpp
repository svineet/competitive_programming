#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string str; cin >> str;
        int n = str.length();
        bool fukt = false;
        for (int i=0; i<=(n-1)/2; i++) {
            char a = str[i],
                 b = str[n-1-i];
            if (a=='.' && b=='.') {
                str[i] = str[n-i-1] = 'a';
            } else if (a=='.') {
                str[i] = str[n-i-1];
            } else if (b=='.') {
                str[n-i-1] = str[i];
            } else if (a == b) {
                continue;
            } else {
                fukt = true; break;
            }
        }
        if (fukt)
            cout << -1 << endl;
        else
            cout << str << endl;
    }
    return 0;
}
