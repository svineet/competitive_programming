#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;
    int array[n];
    for (int i=0; i<n; i++) cin >> array[i];

    int best = 0;
    // best is the number of
    // things we keep
    sort(array, array+n);
    for (int i=0; i<n; i++) {
        int index = lower_bound(array, array+n, ceil(array[i]/2.0))-array;
        best = max(best, i-index+1);
    }

    cout << n-best << endl;
}
