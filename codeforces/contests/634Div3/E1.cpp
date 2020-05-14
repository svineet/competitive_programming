#include <bits/stdc++.h>

#define psum(ch, i, j) (i>j)?0:prefsum[ch][j]-(i==0?0:prefsum[ch][i-1])

using namespace std;


int main(int argc, char **argv) {
    ios::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int arr[n];
        int prefsum[27][n+1];
        // prefsum(character, index) stores number of occ of 'character' in [0, index]

        for (int i=0; i<n; i++) {
            cin >> arr[i];

            for (int ch=1; ch<27; ch++) {
                prefsum[ch][i] = (i?prefsum[ch][i-1]:0) + (ch == arr[i]);
            }
        }

        int ans = 0;
        for (int ch=1; ch<27; ch++) {
            ans = max(ans, prefsum[ch][n-1]);
        }
        //cout << "Init " << ans << endl;

        for (int i=0; i<n; i++) {
            for (int j=i; j<n; j++) {
                // Consider [i, j] as the inner subarray
                // Pick the character with max occurrence
                int inner_max = 0;
                for (int ch=1; ch<27; ch++) {
                    inner_max = max(inner_max, psum(ch, i, j)); // Sum(ch, i, j);
                }

                int cnt = 0;
                // Select outer character
                for (int ch=1; ch<27; ch++) {
                    cnt = max(cnt, min(psum(ch, 0, i-1), psum(ch, j+1, n-1)));
                }

                //cout << i << " " << j << " " << inner_max << " " << cnt << endl;
                ans = max(ans, inner_max+2*cnt);
            }
        }

        cout << ans << endl;
    }

    return 0;
}

