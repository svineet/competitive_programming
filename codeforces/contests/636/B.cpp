#include <bits/stdc++.h>
using namespace std;


int main(int argc, char **argv) {
    int t; cin >> t;
    while (t--) {
        long long n; cin >> n;

        if ((n/2)%2 == 0) {
            cout << "YES" << endl;

            long long sem = 0;
            for (int i=2; i<=n; i+=2) {
                cout << i << " ";
                sem += i;
            }
            for (int i=1; i<=(n/2 - 1); i++) {
                cout << 2*i - 1 << " ";
                sem -= 2*i - 1;
            }
            cout << sem << endl;
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

