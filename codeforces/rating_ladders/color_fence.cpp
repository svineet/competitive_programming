#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a,
          pair<int, int> b) {
    cout << "helo" << endl;
    return a.first < b.first;
}

int main() {
    int n; cin >> n;
    vector<pair<int, int>> digs;
    digs.resize(9);
    for (int i=1; i<=9; i++) {
        cin >> digs[i-1].first;
        digs[i-1].second = i;
    }
    sort (digs.begin(), digs.end(), comp);

    if (n < digs[0].first) {
        cout << -1 << endl;
        return 0;
    }

    vector<char> res;
    res.reserve(n/digs[0].first);
    for (int i=0; i<(n/digs[0].first); i++)
        res.push_back('0'+digs[i].second);

    int left = n%digs[0].first;
    int DIGS = n/digs[0].first;
    for (int i=0; i<DIGS; i++) {
        int mx = digs[0].second;
        int xd = 0;
        for (int j=0; j<9; j++) {
            if (digs[j].first-digs[0].first <= left) {
                if (mx < digs[j].second) {
                    mx = digs[j].second;
                    xd = digs[j].first-digs[0].first;
                }
            }
        }
        res[i] = '0'+mx;
        left -= xd;
    }

    for (int i=0; i<DIGS; i++)
        cout << res[i];
    cout << endl;

    return 0;
}
