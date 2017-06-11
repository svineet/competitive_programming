#include <bits/stdc++.h>
using namespace std;

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

    return 0;
}
