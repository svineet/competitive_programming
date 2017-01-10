#include <bits/stdc++.h>
using namespace std;

const int MOD = 5e6;
int bit[51][200000];

int main() {
    int n; cin >> n;
    int k; cin >> k;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int dp[n+1][k+1];
    // dp[i][j] is the number of ways
    // to form increasing subsequences
    // of length k using first i elements
    memset(dp, 0, sizeof dp);

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=k; j++) {
            int lsum = 0;
            int elem = arr[i-1];
        }
    }

    for (int i=0; i<=n; i++) {
        for (int j=0; j<=k; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << dp[n][k] << endl;

    return 0;
}
