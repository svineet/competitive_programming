#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector< pair<int, string> > regions[m+1];
    for (int i=0; i<n; i++) {
        string str; int r, pts;
        cin >> str >> r >> pts;
        regions[r].push_back(make_pair(pts, str));
    }

    for (int i=1; i<=m; i++) {
        sort (regions[i].begin(), regions[i].end(), greater< pair<int, string> >());
    }

    for (int i=1; i<=m; i++) {
        int len = regions[i].size();
        if (len>2 && regions[i][1].first == regions[i][2].first) {
            cout << "?" << endl;
        } else {
            cout << regions[i][0].second << " " << regions[i][1].second << endl;
        }
    }

    return 0;
}
