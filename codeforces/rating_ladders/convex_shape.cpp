#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    char matrix[n][m];
    for (int i=0; i<n; i++) {
        string str; cin >> str;
        for (int j=0; j<m; j++)
            matrix[i][j] = str[j];
    }

    for (int i_=0; i_<n; i_++) {
        for (int j_=0; j_<m; j_++) {
            for (int k_=0; k_<n; k_++) {
                for (int w_=0; w_<m; w_++) {
                    pair<int, int> a = {i_, j_};
                    pair<int, int> b = {k_, w_};
                    int i, j, k, w;
                    if (a < b) {
                        i = i_; j = j_;
                        k = k_; w = w_;
                    } else {
                        i = k_; j = w_;
                        k = i_; w = j_;
                    }

                    if (matrix[i][j] == 'B' &&
                        matrix[k][w] == 'B') {
                        bool all1 = true,
                             all2 = true;

                        for (int x=i; x<=k; x++)
                            all1 = all1 && matrix[x][j] == 'B';
                        for (int x=j; x<=w; x++)
                            all1 = all1 && matrix[k][x] == 'B';

                        for (int x=i; x<=k; x++)
                            all2 = all2 && matrix[x][w] == 'B';
                        for (int x=j; x<=w; x++)
                            all2 = all2 && matrix[i][x] == 'B';

                        if (!all1 && !all2) {
                            cout << "NO" << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout << "YES" << endl;

    return 0;
}
