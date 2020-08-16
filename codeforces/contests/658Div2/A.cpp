#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        int A[n], B[m];
        for (int i=0; i<n; i++) {
            cin >> A[i];
        }
        for (int i=0; i<m; i++) {
            cin >> B[i];
        }

        bool done = false;
        for (int i=0; i<n && !done; i++) {
            for (int j=0; j<m && !done; j++) {
                if (A[i] == B[j]) {
                    cout << "YES\n";
                    cout << "1 " << A[i] << endl;

                    done = true;
                }
            }
        }

        if (!done) {
            cout << "NO" << endl;
        }
    }

    return 0;
}

