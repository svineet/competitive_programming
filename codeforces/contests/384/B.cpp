#include <bits/stdc++.h>
using namespace std;

long long twopow[100];

int solve (long long n, long long k) {
    if (k == (twopow[n-1])) {
        return n;
    } else {
        return solve(n-1, abs(k-twopow[n-1]));
    }
}

int main() {
    long long n, k; cin >> n >> k;

    twopow[0] = 1;
    for (int i=1; i<55; i++)
        twopow[i] = 2*twopow[i-1];

    cout << solve(n, k) << endl;
    return 0;
}
