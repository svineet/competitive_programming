/*
ID: saivine1
PROG: palsquare
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

char digmap[21] = {
    '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
    'G', 'H', 'I', 'J', 'K'
};

string convert(long long num,
                  int b) {
    string res = "";
    while (num > 0) {
        int d = num%b;
        res += digmap[d];
        num /= b;
    }

    reverse(res.begin(), res.end());
    return res;
}

bool palindrome(string str) {
    int n = str.length();
    for (int i=0; i<n; i++) {
        if (str[i] != str[n-1-i]) return false;
    }
    return true;
}

int main() {
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);

    int b; cin >> b;
    for (int i=1; i<=300; i++) {
        string ib = convert(i, b);
        string isb = convert(i*i, b);
        if (palindrome(isb))
            cout << ib << " " << isb << endl;
    }

    return 0;
}
