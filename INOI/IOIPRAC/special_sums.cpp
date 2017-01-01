#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    long long A[n], B[n];
    for (int i=0; i<n; i++) {
        cin >> A[i];
    }
    for (int i=0; i<n; i++) {
        cin >> B[i];
    }

    long long fmax = -1e18;
    long long left[n], right[n];
    left[0] = A[0];
    for (int i=1; i<n; i++) {
        left[i] = max(left[i-1]+B[i],
                      A[i]);
    }
    right[n-1] = A[n-1];
    for (int i=n-2; i>=0; i--) {
        right[i] = max(right[i+1]+B[i],
                       A[i]);
    }

    for (int i=0; i<n-1; i++) {
        fmax = max(fmax, left[i]+right[i+1]);
    }

    long long suff[n], pref[n];
    // Suff stores best suffix
    // Pre stores prefix;
    long long runsum = A[0];
    pref[0] = A[0];
    for (int i=1; i<n; i++) {
        runsum = runsum-A[i-1]+B[i-1]+A[i];
        pref[i] = max(pref[i-1], runsum);
    }

    runsum = A[n-1];
    suff[n-1] = A[n-1];
    for (int i=n-2; i>=0; i--) {
        runsum = runsum - A[i+1]+B[i+1]+A[i];
        suff[i] = max(suff[i+1], runsum);
    }

    for (int i=0; i<n-1; i++) {
        // Crossing segment is a sum
        // of suffix and prefix.
        fmax = max(fmax, pref[i]+suff[i+1]);
    }
    cout << fmax << endl;

    return 0;
}
