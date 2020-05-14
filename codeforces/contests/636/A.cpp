#include <bits/stdc++.h>
using namespace std;


int main(int argc, char **argv) {
    int t; cin >> t;
    while (t--) {
        long long n; cin >> n;
        long long pow2 = 4;

        for (int k=2; k<=32; k++) {
            if (n%(pow2-1) == 0) {
                cout << n/(pow2-1) << endl;
                break;
            }
            pow2 *= 2;
        }
    }

    return 0;
}

