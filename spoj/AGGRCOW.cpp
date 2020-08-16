#include <bits/stdc++.h>
using namespace std;


bool allocation_possible (int pos[], int n, int cows, int dist) {
    int assigned = 1, last_assigned = pos[0]; // Assign a cow in first post
    for (int i=1; i<n && assigned < cows; i++) {
        if (pos[i] - last_assigned >= dist) {
            last_assigned = pos[i];
            assigned++;
        }
    }

    return (assigned == cows);
}


int main(int argc, char **argv) {
    int t; cin >> t;
    while (t--) {
        int n, c; cin >> n >> c;

        int pos[n];
        for (int i=0; i<n; i++) cin >> pos[i];
        sort (pos, pos+n);

        int left = 1, right = 1000000001;
        int ans = 1;
        while (left < right) {
            int mid = (left+right)/2;
            if (allocation_possible(pos, n, c, mid)) {
                // Go toward [mid..right]
                ans = mid;
                left = mid+1;
            } else {
                // Go towards [left..mid-1]
                right = mid-1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}

