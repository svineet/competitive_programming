#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 9;
long long ModExp(long long base,
                 long long power) {
    if (power == 0) return 1;
    if (power == 1) return base%MOD;

    if (power%2) {
        return (base*ModExp(base, power-1))%MOD;
    } else {
        long long intermediate = ModExp(base, power/2)%MOD;
        return (intermediate*intermediate)%MOD;
    }
}


int main() {
    int n, m, k; cin >> n >> m >> k;
    long long X = max(0, m - n/k*(k-1) - n%k);
    long long powered = (MOD+(ModExp(2, X+1)-2)*k+m-X*k)%MOD;
    cout << powered << endl;

    return 0;
}
