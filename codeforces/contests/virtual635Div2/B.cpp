#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
    int t; cin >> t;
    while (t--) {
        int x, n, m; cin >> x >> n >> m;

        while (n > 0 && x > 0) {
            if (x <= 20) break;
            x = x/2 + 10;
            n--;
        }

        while (m > 0 && x > 0) {
            x -= 10;
            m--;
        }

        if (x > 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}

