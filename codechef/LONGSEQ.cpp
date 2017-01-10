#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string str; cin >> str;
        int n = str.length();
        int a = 0, b = 0;
        for (int i=0; i<n; i++) {
            if (str[i] == '1') a++;
            else if (str[i] == '0') b++;
        }

        if (a==1 || b==1) cout << "Yes" << endl;
        else              cout << "No" << endl;
    }

    return 0;
}
