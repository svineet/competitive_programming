#include <bits/stdc++.h>
using namespace std;

int n;
char matr[100][100];

void flip(int r, int c) {
    for (int i=0; i<=r; i++)
        for (int j=0; j<=c; j++)
            matr[i][j] = matr[i][j]=='0'?'1':'0';
}

int main() {
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);

    cin >> n;
    for (int i=0; i<n; i++) {
        string str; cin >> str;
        for (int j=0; j<n; j++) matr[i][j] = str[j];
    }

    int cnt = 0;
    for (int i=n-1; i>=0; i--) {
        for (int j=n-1; j>=0; j--) {
            if (matr[i][j] == '1') {
                flip(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}
