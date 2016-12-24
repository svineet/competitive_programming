#include <bits/stdc++.h>
using namespace std;

int main() {
    int total; cin >> total;
    int n; cin >> n;
    long long array[n];
    long long sm = 0;
    for (int i=0; i<n; i++) {
        cin >> array[i]; sm += array[i];
    }
    int dp[n][total+1];
    int parent[n][total+1];
    // parent[i][j] == if i was taken to form j
    // or not.
    for (int i=0; i<=total; i++) {
        dp[0][i] = i==array[0]?1:0;
        parent[0][i] = i==array[0]?1:0;
    }
    dp[0][0] = 1;
    parent[0][0] = 0;
    // Don't take this element and get a sum of zero
 
    for (int i=1; i<n; i++) {
        for (int j=0; j<=total; j++) {
            dp[i][j] = dp[i-1][j];
            parent[i][j] = 0;
            if (array[i]<=j && dp[i-1][j-array[i]]>=1) {
                parent[i][j] = 1;
                dp[i][j] += dp[i-1][j-array[i]];
            }
        }
    }

    if (dp[n-1][total] == 1) {
        vector<int> missing;
        long long cur = total;
        bool fukt = false;
        for (int i=n-1; i>=0; i--) {
            assert (cur >= 0);
            if (dp[i][cur] > 1) {
                fukt = true;
                break;
            } else {
                if (parent[i][cur] == 0)
                    missing.push_back(i+1);
                else
                    cur -= array[i];
            }
        }

        if (fukt) {
            cout << -1 << endl;
            return 0;
        }

        int len = missing.size();
        for (int i=len-1; i>=0; i--)
            cout << missing[i] << " ";
        cout << endl;
    } else if (dp[n-1][total] == 0) {
        cout << 0 << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
