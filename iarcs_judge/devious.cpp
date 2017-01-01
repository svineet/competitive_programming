#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int array[n];
    long long sm = 0;
    vector< pair<long long, int> > cml;
    for (int i=0; i<n; i++) {
        cin >> array[i];
        sm += array[i];
        cml.push_back(make_pair(sm, i+1));
    }

    sort (cml.begin(), cml.end());

    long long best = 1e18;
    int start = 0, end = 0;
    for (int i=0; i<n-1; i++) {
        // cout << cml[i].first << " " << cml[i].second << endl;
        long long diff = cml[i+1].first-cml[i].first;
        if (diff<best) {
            best = diff;
            start = cml[i].second;
            end = cml[i+1].second;
        } else if (diff == best) {
            if (abs(end-start) < abs(cml[i+1].second-cml[i].second)) {
                start = cml[i].second;
                end = cml[i+1].second;
            }
        }
    }

    int s1 = min(start, end)+1,
        e1 = max(start, end);

    best = 0;
    for (int i=s1-1; i<e1; i++) best += array[i];

    cout << best << endl;
    cout << s1 << " " << e1 << endl;

    return 0;
}
