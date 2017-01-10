#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> start, end;
    start.reserve(n/2); end.reserve(n/2);
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for (int i=0; i<n-1; i++) {
        start.push_back(min(arr[i], arr[i+1]));
        end.push_back(max(arr[i+1], arr[i]));
    }
    sort (start.begin(), start.end());
    sort (end.begin(), end.end());

    int entries = 0,
        exits = 0;
    int best = 0;
    int lptr = 0,
        rptr = 0;
    while (lptr<n-1 && rptr<n-1) {
        if (start[lptr]<end[rptr]) {
            entries++;
            lptr++;
        } else {
            exits++;
            rptr++;
        }
        best = max(best, entries-exits);
    }

    cout << best << endl;

    return 0;
}
