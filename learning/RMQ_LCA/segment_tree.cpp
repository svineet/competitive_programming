#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int array[n];
    for (int i=0; i<n; i++) cin >> array[i];

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

    return 0;
}
