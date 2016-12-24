#include <bits/stdc++.h>
using namespace std;

/*
 * Range Minimum Query using
 * square root decomposition.
 */

int main() {
    int n; cin >> n;
    int array[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }

    int sqrtlen = ceil(sqrt(n));
    int sqrtseglen = floor(sqrt(n));
    int sqrtdec[sqrtlen];
    for (int i=0; i<sqrtlen; i++) {
        int curmin = 1e9;
        for (int j=i*sqrtseglen; j<min(n, (i+1)*sqrtseglen); j++) {
            curmin = min(curmin, array[j]);
        }
        sqrtdec[i] = curmin;
    }

    int q; cin >> q;
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            // RMQ
            int a, b; cin >> a >> b;
        } else if (type == 2) {
            // Update array[a]
            // to b
            int a, b; cin >> a >> b;
        }
    }
}
