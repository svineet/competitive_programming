#include <bits/stdc++.h>
using namespace std;

bool asieve[1000001];

int main() {
    ios::sync_with_stdio(false);
    for (int i=4; i<1000001; i+=2)
        asieve[i] = true;

    for (long long i=3; i<1000001; i+=2) {
        if (!asieve[i]) {
            for (long long j=i*i; j<1000001; j+=i) {
                asieve[j] = true;
            }
        }
    }

    int t; cin >> t;
    while (t--) {
        long long n; cin >> n;
        long long best_fac = -1;
        for (long long i=2; i<=sqrt(n); i++) {
            if (!asieve[i] && n%i==0) {
                best_fac = max(best_fac, i);
                n /= i;
                i--;
            }
        }

        if (n != 1) {
            cout << n << endl;
            /*bool prim = true;
            for (int i=2; i<=sqrt(n) && prim; i++) {
                if (n%i == 0) prim = false;
            }

            if (prim) cout << n << endl;*/
        } else {
            cout << best_fac << endl;
        }
    }

    return 0;
}
