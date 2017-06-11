#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int a; cin >> a;
        if (a == 180) {
            cout << "NO" << endl;
            continue;
        }

        if (360%(180-a) == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
