#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m, k, x, y;
    cin >> n >> m >> k >> x >> y;

    long long cnt[2*n+1][m+1];
    long long sweeps = k/(2*n*m-m);
    for (int i=1; i<2*n; i++) {
        for (int j=1; j<=m; j++) {
            cnt[i][j] = sweeps;
        }
    }

    k = k%(2*n*m-m);
    for (int i=1; i<2*n; i++) {
        if (k==0) break;
        for (int j=1; j<=m; j++) {
            if (k==0) break;
            cnt[i][j]++;
            k--;
        }
    }

    long long mx = -1e18,
              mn = 1e18;
    for (int i=1; i<n; i++) {
        for (int j=1; j<=m; j++) {
            cnt[i][j] += cnt[2*n-i][j];
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            mx = max(mx, cnt[i][j]);
            mn = min(mn, cnt[i][j]);
        }
    }
    cout << mx << " " << mn << " " << cnt[x][y] << endl;

    return 0;
}
