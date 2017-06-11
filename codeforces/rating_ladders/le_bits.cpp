#include <bits/stdc++.h>
using namespace std;

int main() {
    string str; cin >> str;
    int n = str.length();
    int ones = count(str.begin(), str.end(), '1');

    if (ones == n) {
        for (int i=0; i<n-1; i++) cout << 1;
    } else {
        bool rem = false;
        for (int i=0; i<n; i++) {
            if (!rem && str[i] == '0') {
                rem = true;
                continue;
            }
            cout << str[i];
        }
    }
    cout << endl;

    return 0;
}
