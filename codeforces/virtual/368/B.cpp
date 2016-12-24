#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k; cin >> n >> m >> k;
    vector< pair<int, int> > adjlist[n+1];
    bool infected[n+1] = {false};
    for (int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        int w; cin >> w;
        adjlist[a].push_back(make_pair(b, w));
        adjlist[b].push_back(make_pair(a, w));
    }

    for (int i=0; i<k; i++) {
        int a; cin >> a;
        infected[a] = true;
    }

    long long best = 1e18;
    for (int i=1; i<=n; i++) {
        if (infected[i]) {
            int len = adjlist[i].size();
            for (int j=0; j<len; j++) {
                int nx = adjlist[i][j].first;
                int weight = adjlist[i][j].second;
                if (!infected[nx] && weight<best)
                    best = weight;
            }
        }
    }
    if (best == 1e18)
        cout << "-1" << endl;
    else
        cout << best << endl;

    return 0;
}
