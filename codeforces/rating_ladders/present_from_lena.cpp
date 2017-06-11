#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    for (int i=-n; i<=n; i++) {
        string cur = "";
        for (int j=-n; j<=n; j++) {
            // print n - manhattan dist
            // from 0, 0

            if (i < 0 && j > 0 && abs(i)+j>n)
                continue;
            if (i > 0 && j > 0 && j+i>n)
                continue;

            if (abs(i) + abs(j) > n)
                cur += " ";
            else
                cur += '0'+(n - (abs(i)+abs(j)));
        }

        for (int i=0; i<cur.length(); i++) {
            cout << cur[i];
            if (i != cur.length() - 1)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}
