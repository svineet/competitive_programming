#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
long long dp[1000001];
long long partials[1000001];

int main() {
    int n, k; cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        partials[i] = (i>0?partials[i-1]:0)+arr[i];
    }

    long long best = partials[k-1];
    dp[k-1] = partials[k-1];
    for (int i=k; i<n; i++) {
        dp[i] = max(dp[i-1]+arr[i], partials[i]-partials[i-k]);
        best = max(best, dp[i]);
    }

    cout << best << endl;

    return 0;
}
