#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a,
              long long b) {
    if (b==0) return a;
    return gcd(b, a%b);
}

int main() {
    long long n; cin >> n;
    if (n==1) {
        cout << 1 << endl;
        return 0;
    } else if (n==2) {
        cout << 2 << endl;
        return 0;
    }

    if (n%2!=0) {
        cout << n*(n-1)*(n-2) << endl;
    } else {
        long long best = 0;
        for (long long i=max(1ll, n-100); i<=n; i++) {
            for (long long j=i; j<=n; j++) {
                for (long long k=j; k<=n; k++) {
                    long long flcm = (i*j)/gcd(i, j);
                    long long dlcm = (flcm*k)/gcd(flcm, k);
                    best = max(best, dlcm);
                }
            }
        }
        cout << best << endl;
    }

    return 0;
}
