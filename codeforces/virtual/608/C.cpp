#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    pair<int, int> bcons[n];
    for (int i=0; i<n; i++) {
        cin >> bcons[i].first >> bcons[i].second;
    }
    sort (bcons, bcons+n);

    int dp[n];
    // dp[i] is the minimum number of beacons
    // that will be destroyed to the left
    // of beacon i if we activate
    // the i-th beacon.
    dp[0] = 0; // Nothing to the left of the first beacon
    for (int i=1; i<n; i++) {
        int lo = lower_bound(bcons, bcons+n,
                 make_pair(bcons[i].first-bcons[i].second, numeric_limits<int>::min()))-bcons;
        dp[i] = (lo>0?dp[lo-1]:0)+i-lo;
    }

    int best = n;
    // Destroy all of them
    for (int i=n-1; i>=0; i--) {
        best = min(best, n-i+(i>0?dp[i-1]:0));
    }
    cout << min(best, dp[n-1]) << endl;

    return 0;
}
