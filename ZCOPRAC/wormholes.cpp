#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, entry, exit;
    cin >> n >> entry >> exit;
    pair<int, int> array[n];
    for (int i=0; i<n; i++) {
        cin >> array[i].first >> array[i].second;
    }

    int starts[entry], ends[exit];
    for (int i=0; i<entry; i++) {
        cin >> starts[i];
    }
    for (int i=0; i<exit; i++) {
        cin >> ends[i];
    }

    sort (array, array+n);
    sort (starts, starts+entry);
    sort (ends, ends+exit);

    int best = 1e9;
    for (int i=0; i<n; i++) {
        int lptr = upper_bound(starts, starts+entry, array[i].first)-starts-1;
        if (lptr == -1)
            continue;
        int rptr = lower_bound(ends, ends+exit, array[i].second)-ends;
        if (rptr==exit)
            continue;
        best = min(best, ends[rptr]-starts[lptr]+1);
    }

    cout << best << endl;

    return 0;
}
