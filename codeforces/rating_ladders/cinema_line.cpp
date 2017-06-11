#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int n25 = 0,
        n50 = 0,
        n100 = 0;

    for (int i=0; i<n; i++) {
        int a; cin >> a;
        if (a == 25) {
            n25++;
        } else if (a == 50) {
            if (n25 > 0)
                n25--;
            else {
                cout << "NO" << endl;
                return 0;
            }
            n50++;
        } else {
            if (n50 > 0 && n25 > 0) {
                n50--; n25--;
            } else if (n25 > 2) {
                n25 -= 3;
            } else {
                cout << "NO" << endl;
                return 0;
            }
            n100++;
        }
    }

    cout << "YES" << endl;

    return 0;
}
