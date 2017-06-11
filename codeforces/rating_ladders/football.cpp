#include <bits/stdc++.h>
using namespace std;

int main() {
    string str; cin >> str;
    int n = str.length();

    for (int i=0; i<n; i++) {
        bool all_same = true;
        if (i+6 > n) break;
        for (int j=i; j<i+7; j++) {
            all_same = all_same && str[j] == str[i];
        }

        if (all_same) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}
