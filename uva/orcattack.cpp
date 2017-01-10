#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    int oldt = t;
    while (t--) {
        int L; cin >> L;
        int adj[L+1][L+1];
        for (int i=1; i<=L; i++) {
            for (int j=1; j<=L; j++) {
                if (i==j) adj[i][j] = 0;
                else      adj[i][j] = 1e9+10;
            }
        }

        int d; cin >> d;
        for (int idc=1; idc<=d; idc++) {
            int a, b, c; cin >> a >> b >> c;
            adj[a][b] = min(adj[a][b], c);
            adj[b][a] = min(adj[b][a], c);
        }

        for (int k=1; k<=L; k++) {
            for (int i=1; i<=L; i++) {
                for (int j=1; j<=L; j++) {
                    adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
                }
            }
        }

        int oldmx = 1e9;
        bool found = false;
        for (int node=6; node<=L; node++) {
            bool equals = true;
            for (int byld=2; byld<=5; byld++) {
                if (adj[node][byld] != adj[node][byld-1] || adj[node][byld] == 1e9+10)
                    equals = false;
            }

            bool allreach = true;
            for (int i=1; i<=L; i++)
                if (adj[node][i] == 1e9+10) allreach = false;

            if (equals && allreach) {
                //cout << node << " " << adj[node][1] << endl;
                int mx = -1e8;
                for (int i=1; i<=L; i++) {
                    mx = max(mx, adj[node][i]);
                }
                // cout << mx << endl;
                oldmx = min(oldmx, mx);

                found = true;
            }
        }

        cout << "Map " << oldt-t << ": ";
        if (found) {
            cout << oldmx << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
