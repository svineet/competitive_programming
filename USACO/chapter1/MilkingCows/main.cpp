/*
ID: saivine1
PROG: milk2
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a,
          pair<int, int> b) {
    return a.second<b.second;
}

int main() {
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);

    int n; cin >> n;
    vector< pair<int, bool> > times;
    times.reserve(2*n);
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        times.push_back({a, false});
        times.push_back({b, true});
    }
    sort (times.begin(), times.end());

    int tym = times[0].first;
    // cout << tym << endl;
    int tptr = 1;
    int cur = 1;
    int best_wide = 0,
        best_short = 0;
    int cur_wide = 0,
        cur_short = 0;
    while (tptr < 2*n) {
        // cout << tym << " " << times[tptr].first << endl;
        while (tym == times[tptr].first) {
            if (times[tptr].second)
                cur--;
            else
                cur++;
            tptr++;
        }

        if (cur >= 1) {
            cur_wide++;
            cur_short = 0;
        }
        if (cur == 0) cur_wide = 0;
        if (cur == 0 && tptr != 2*n) cur_short++;

        best_wide = max(best_wide, cur_wide);
        best_short = max(best_short, cur_short);
        tym++;
    }

    /*for (int i=0; i<n; i++) {
        int mx = -1e8;
        for (int j=0; j<n; j++) {
            if (j == i) continue;
            if (t2[j].second < t2[i].second)
                mx = max(mx, t2[j].second);
        }
        if (mx == -1e8) continue;
        best_short = max(best_short,
                         t2[i].first-mx);
    }*/

    cout << best_wide << " " << best_short << endl;

    return 0;
}
