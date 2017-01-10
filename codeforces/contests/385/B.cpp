#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    char matrix[n][m];
    for (int i=0; i<n; i++) {
        string str; cin >> str;
        for (int j=0; j<m; j++) {
            matrix[i][j] = str[j];
        }
    }

    int lx = 1e8, ly = 1e8;
    int mx = -1e8, my = -1e8;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (matrix[i][j] == 'X') {
                lx = min(lx, i);
                ly = min(ly, j);
                mx = max(mx, i);
                my = max(my, j);
            }
        }
    }

    if (lx != 1e8 && mx != -1e8) {
        bool fukt = false;
        for (int i=lx; i<=mx; i++) {
            for (int j=ly; j<=my; j++) {
                if (matrix[i][j] != 'X') {
                    fukt = true;
                    break;
                }
            }
            if (fukt) break;
        }
        if (!fukt)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
