#include <bits/stdc++.h>
using namespace std;

int matrix[100][100];
long long op = 0;

bool solve(int n, int dex, int move_left) {
    op++;
    printf("%lld ", op);
    if (move_left == 0) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (matrix[i][j] == 1) return false;
                // Tipped, return false.
                op++;
            }
        }

        return true;
        // All fine.
    }

    int fi = dex/n,
        fj = dex%n;
    if (!(fi>=0 && fi<n && fj>=0 && fj<n)) return false;
    // Rectangle boundaries to flip.
    // First try to flip that and see if we
    // make any progress.
    for (int i=0; i<=fi; i++) {
        for (int j=0; j<=fj; j++) {
            matrix[i][j] = 1-matrix[i][j];
            op++;
        }
    }
    if (solve(n, dex+1, move_left-1)) {
        return true; 
    } else {
        for (int i=0; i<=fi; i++) {
            for (int j=0; j<=fj; j++) {
                matrix[i][j] = 1-matrix[i][j];
                op++;
            }
        }
        // Undo the flips and try not taking this move.
        return solve(n, dex+1, move_left);
    }
}

int main() {
    ios::sync_with_stdio(false);
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);

    int n; cin >> n;
    bool allzero = true;
    for (int i=0; i<n; i++) {
        string str; cin >> str;
        for (int j=0; j<n; j++) {
            matrix[i][j] = int(str[j]-'0');
            if (matrix[i][j] == 1) allzero = false;
        }
    }

    if (allzero) {
        cout << 0 << endl;
        return 0;
    }

    bool done = false;
    for (int i=1; i<=n*n; i++) {
        // Flip i rectangles.
        done = solve(n, 0, i);
        if (done) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}
