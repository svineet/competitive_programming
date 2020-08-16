#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string a, b; cin >> a >> b;

        int diff = 0;
        for (int i=0; i<n; i++)
            diff += (a[i] == b[i])? 0: 1;

        vector<int> ops;
        /*
        if (diff >= 2*n/3) {
            // Flip it and invert it
            for (int i=0; i<n/2; i++) {
                a[i] = (a[n-i] == '0')? '1': '0';
            }
            ops.push_back(n);
        }
        */

        for (int i=n-1; i>=0; i--) {
            if (a[i] != b[i]) {
                // Invert operation must be carried out
                if (i != 0) ops.push_back(i+1);
                ops.push_back(1);
                if (i != 0) ops.push_back(i+1);
                a[i] = b[i];
            }
        }

        int k = ops.size();
        cout << k << " ";
        for (int i=0; i<k; i++) cout << ops[i] << " ";
        cout << endl;
    }

    return 0;
}

