#include <bits/stdc++.h>
using namespace std;

int increase[100005];
int decrease[100005];

int main() {
    int n, q; cin >> n >> q;
    int array[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }

    increase[n-1] = n-1;
    // increase[i] gives us the largest index j
    // such that A[i..j] is increasing (weakly)
    // decrease[i] gives us the same for
    // weakly decreasing sequence.
    for (int i=n-2; i>=0; i--) {
        if (array[i]<=array[i+1]) {
            increase[i] = increase[i+1];
        } else {
            // Streak broken
            increase[i] = i;
        }
    }

    decrease[n-1] = n-1;
    for (int i=n-2; i>=0; i--) {
        if (array[i]>=array[i+1]) {
            decrease[i] = decrease[i+1];
        } else {
            decrease[i] = i;
        }
    }

    while (q--) {
        int l, r; cin >> l >> r;
        l--; r--;

        if (decrease[increase[l]] >= r)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
