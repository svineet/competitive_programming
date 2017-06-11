/*
ID: saivine1
PROG: dualpal
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

bool is_palin(string a) {
    int len = a.length();
    for (int i=0; i<len/2; i++)
        if (a[i] != a[len-i-1]) return false;
    return true;
}

string convert(int n, int b) {
    string res = "";
    while (n>0) {
        res = char('0'+n%b)+res;
        n /= b;
    }
    return res;
}

int main() {
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);

    int n, s; cin >> n >> s;
    s++;

    int nums = 0;
    while (nums<n) {
        int bases = 0;
        for (int i=2; i<=10; i++) {
            if (is_palin(convert(s, i))) {
                bases++;
            }
        }

        if (bases>=2) {
            cout << s << endl;
            nums++;
        }
        s++;
    }

    return 0;
}
