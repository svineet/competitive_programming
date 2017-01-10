#include <bits/stdc++.h>
using namespace std;

int main() {
    string str; cin >> str;
    int n = str.length();

    int lever = -1;
    for (int i=0; i<n; i++) {
        if (str[i] == '^') {
            lever = i; break;
        }
    }

    long long left = 0, right = 0;
    for (int j=lever-1; j>=0; j--) {
        if (str[j] == '=') continue;
        int num = str[j]-'0';
        left += (lever-j)*num;
    }
    for (int j=lever+1; j<n; j++) {
        if (str[j] == '=') continue;
        int num = str[j]-'0';
        right += (j-lever)*num;
    }

    if (right == left)   cout << "balance";
    else if (right>left) cout << "right";
    else                 cout << "left";
    cout << endl;
}
