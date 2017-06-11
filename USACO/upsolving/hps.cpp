#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int n; cin >> n;
    char moves[n];
    int last[n+1][3],
        frst[n+1][3];
    for (int i=0; i<n; i++) {
        string s; cin >> s;
        moves[i] = s[0];
    }

    frst[0][0] = frst[0][1] = frst[0][2] = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<3; j++)
            frst[i+1][j] = frst[i][j];

        if (moves[i] == 'H') {
            frst[i+1][1]++;
        } else if (moves[i] == 'P') {
            frst[i+1][2]++;
        } else if (moves[i] == 'S') {
            frst[i+1][0]++;
        }
    }

    last[0][0] = last[0][1] = last[0][2] = 0;
    for (int i=n-1; i>=0; i--) {
        for (int j=0; j<3; j++)
            last[n-i][j] = last[n-i-1][j];

        if (moves[i] == 'H') {
            last[n-i][1]++;
        } else if (moves[i] == 'P') {
            last[n-i][2]++;
        } else if (moves[i] == 'S') {
            last[n-i][0]++;
        }
    }

    int mx = 0;
    for (int i=0; i<=n; i++) {
        // If first i are HPS
        // and rest are HPS
        mx = max({mx,
                 frst[i][0]+max(last[n-i][1],
                                last[n-i][2]),
                 frst[i][1]+max(last[n-i][0],
                                last[n-i][2]),
                 frst[i][2]+max(last[n-i][0],
                                last[n-i][1])});
    }
    cout << mx << endl;

    return 0;
}
