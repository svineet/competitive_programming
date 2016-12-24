#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n; cin >> n;
    string str; cin >> str;

    int fa, fg, fc, ft;
    fa = fg = fc = ft = 0;

    for (int i=0; i<n; i++) {
        if (str[i] == 'A')
            fa++;
        if (str[i] == 'G')
            fg++;
        if (str[i] == 'C')
            fc++;
        if (str[i] == 'T')
            ft++;
    }

    long long fact[n+1];
    fact[1] = 1;
    for (int i=2; i<=n; i++) {
        fact[i] = i*fact[i-1];
        fact[i] %= MOD;
    }

    return 0;
}
