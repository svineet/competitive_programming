#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, a, b; cin >> n >> k >> a >> b;
    // a == green, b == black.
    char res[n];
    int cons = 0;
    bool fukt = false;
    for (int i=0; i<n; i++) {
        if (cons==k) {
            if (res[i-1] == 'B') {
                res[i] = 'G';
                a--;
                if (a<0) {
                    fukt = true; break;
                }
            } else {
                res[i] = 'B';
                b--;
                if (b<0) {
                    fukt = true; break;
                }
            }
            cons = 1;
            continue;
        }

        if (a>=b) {
            res[i] = 'G';
            a--;
        } else if (a<b) {
            res[i] = 'B';
            b--;
        }

        if (i==0 || res[i-1] == res[i])
            cons++;
        else
            cons = 1;
        // cout << res[i] << " " << cons << endl;
    }

    if (fukt)
        cout << "NO" << endl;
    else {
        for (int i=0; i<n; i++)
            cout << res[i];
        cout << endl;
    }

    return 0;
}
