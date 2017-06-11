#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);
    
    // Count connected components in implied
    // graph. For each component
    // if it touches the left or top edge
    // we deduct one point of operation.
    // we start with 4 operations.

    int n; cin >> n;
    int comp[n][n];
    int matrix[n][n];
    memset(comp, 0, sizeof comp);
    memset(matrix, 0, sizeof matrix);
    // 0 means unset.

    for (int i=0; i<n; i++) {
        string str; cin >> str;
        for (int j=0; j<n; j++) {
            matrix[i][j] = int(str[j]-'0');
        }
    }

    int addx[4] = {0, 1, 1, -1},
        addy[4] = {1, 0, 0, 0};
    int curcomp = 1;
    long long moves = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (matrix[i][j] == 1 && comp[i][j] == 0) {
                stack<pair<int, int>> S;
                comp[i][j] = curcomp;
                S.push({i, j});
                bool touchleft = false,
                     touchup = false,
                     touchorigin = (i == 0 && j == 0),
                     touchright = false,
                     touchdown = false;
                while (!S.empty()) {
                    int x = S.top().first,
                        y = S.top().second;
                    if (x == 0) touchup = true;
                    if (y == 0) touchleft = true;
                    if (x == n-1) touchright = true;
                    if (y == n-1) touchdown = true;
                    S.pop();
                    for (int k=0; k<2; k++) {
                        int nx = x+addx[k],
                            ny = y+addy[k];
                        if (nx>=0 && nx<n &&
                            ny>=0 && ny<n &&
                            matrix[nx][ny] == 1 &&
                            comp[nx][ny] == 0) {
                            comp[nx][ny] = curcomp;
                            S.push({nx, ny});
                        }
                    }
                }
                curcomp++;

                if (touchleft && touchright) {
                    if (touchtop) {
                        moves += 1;
                    } else {
                        moves += 2;
                    }
                    continue;
                }

                if (touchleft && touchtop) {
                    if (touchorigin)
                        moves++;
                    else
                        moves += 2;
                    continue;
                }

            }
        }
    }

    cout << moves << endl;

    return 0;
}
