#include <bits/stdc++.h>
using namespace std;

bool adj[100][100];

int main() {
    int n; cin >> n;
    string teams[n][3];
    for (int i=0; i<n; i++) {
        for (int j=0; j<3; j++) {
            cin >> teams[i][j];
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            bool ye = false;
            for (int k=0; k<3; k++) {
                for (int w=0; w<3; w++) {
                    if (teams[i][k] == teams[j][w]) {
                        ye = true;
                        break;
                    }
                }
            }
            adj[i][j] = adj[j][i] = ye;
        }
    }

    int best = 0;
    for (int bit = 1; bit< (1<<n); bit++) {
        int cnt = 0;
        bool fukt = false;
        for (int j=0; j<n; j++) {
            if (1<<j & bit) cnt++;
        }

        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if ((1<<i & bit) && (1<<j & bit) && adj[i][j])
                    fukt = true;
                if (fukt) break;
            }
            if (fukt) break;
        }

        if (!fukt) best = max(best, cnt);
    }
    cout << best << endl;

    return 0;
}
