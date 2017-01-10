#include <bits/stdc++.h>
using namespace std;

int white[1005],
    black[1005];
long long dp[1005][2];

int main() {
    int n, m, x, y; cin >> n >> m >> x >> y;
    for (int i=0; i<n; i++) {
        string str; cin >> str;
        for (int j=0; j<m; j++) {
            if (str[j] == '#') {
                white[j]++;
            } else if (str[j] == '.') {
                black[j]++;
            }
        }
    }

    for (int i=0; i<m; i++) {
        dp[i][0] = dp[i][1] = 1e8;
        // 0 is if we painted this suffix
        // white, and 1 if we did black
        long long sumw = 0, sumb = 0;
        for (int j=i; j>i-y; j--) {
            if (j<0) break;

            sumw += white[j];
            sumb += black[j];
            if (i-j+1<x) continue;

            dp[i][0] = min(dp[i][0],
                          (j-1>=0?dp[j-1][1]:0)+sumw);
            dp[i][1] = min(dp[i][1],
                           (j-1>=0?dp[j-1][0]:0)+sumb);
        }
    }

    cout << min(dp[m-1][0], dp[m-1][1]) << endl;
    /*for (int i=0; i<m; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;*/

    return 0;
}
