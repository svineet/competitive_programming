#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<int, int> a,
                pair<int, int> b) {
    // True if a < b;
    // cout << b.first << ";" << b.second << endl;
    return a.first<b.second;
}

bool comp2(pair<int, int> a,
           pair<int, int> b) {
    return make_pair(a.second, a.first)<make_pair(b.second, b.first);
}

const int MOD = 1e8;

int main() {
    int n; scanf("%d", &n);
    while (n != -1) {
        pair<int, int> arr[n];
        for (int i=0; i<n; i++) {
            scanf("%d%d", &arr[i].first, &arr[i].second);
        }
        sort (arr, arr+n, comp2);

        int dp[n]; dp[0] = 1;
        for (int i=1; i<n; i++) {
            int dex = upper_bound(arr, arr+n, arr[i], comparator)-arr;
            dp[i] = (dex>0?dp[dex-1]:0)+1;
            dp[i] += dp[i-1];
            dp[i] %= MOD;
        }

        printf("%08d\n", dp[n-1]);
        scanf("%d", &n);
    }

    return 0;
}
