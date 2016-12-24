#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    pair<int, int> time[n];
    for (int i=0; i<n; i++) {
        cin >> time[i].first >> time[i].second;
    }
    sort (time, time+n);

    int cnt = 0; int max = 0;
    for (int i=0; i<n; i++) {
        if (time[i].second<max) cnt++;
        if (time[i].second>max)
            max = time[i].second;
    }
    cout << cnt << endl;

    return 0;
}
