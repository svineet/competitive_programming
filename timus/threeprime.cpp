#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 9;
long long tenpows[20000];
bool antisieve[20000];
int main() {
    int n; cin >> n;
    int totprimes = 0, thrprimes = 0;
    for (int i=2; i<20000; i++) {
        if (!antisieve[i]) {
            for (int j=i*i; j<20000; j+=i) {
                antisieve[j] = true;
            }
            if (i<1000) totprimes++;
            if (i<1000 && i>100) thrprimes++;
        }
    }

    long long dp[n+1];
    long long tenpow[n+1];
    // dp[i] is the number of
    // three primes that are
    // possible with i digits
    dp[1] = dp[2] = 0; dp[3] = thrprimes;
    tenpow[0] = 1; tenpow[1] = 10; tenpow[2] = 100; tenpow[3] = 1000;
    for (int i=4; i<=n; i++) {
        dp[i] = 9*tenpow[i-4]*thrprimes;
        dp[i] %= MOD;
        tenpow[i] = tenpow[i-1]*10;
        tenpow[i] %= MOD;
    }
    cout << dp[n] << endl;
}
