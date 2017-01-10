#include <bits/stdc++.h>
using namespace std;

vector< pair<int, long long> > adjlist[2005];
long long adjmatrix[2005][2005];
bool visited[2005];
long long dist[2005];

int main() {
    ios::sync_with_stdio(false);
    int m; cin >> m;
    int source, dest; cin >> source >> dest;

    for (int i=1; i<2005; i++) {
        dist[i] = 1e17; visited[i] = false;
    }

    for (int i=0; i<m; i++) {
        long long a, w, b;
        cin >> a >> w >> b;

        if (adjmatrix[a][b] == 0) {
            adjmatrix[a][b] = w; adjmatrix[b][a] = w;
        } else {
            adjmatrix[a][b] = adjmatrix[b][a] = min(adjmatrix[a][b], w);
        }
    }

    for (int i=1; i<=2000; i++) {
        for (int j=1; j<=2000; j++) {
            if (adjmatrix[i][j]) {
                adjlist[i].push_back(make_pair(j, adjmatrix[i][j]));
            }
        }
    }

    set< pair<long long, int> > S;

    dist[source] = 0;
    S.insert(make_pair(dist[source], source));
    while (!S.empty()) {
        int node = S.begin()->second;
        S.erase(S.begin());

        if (visited[node]) continue;
        visited[node] = true;

        int len = adjlist[node].size();
        for (int i=0; i<len; i++) {
            int nx = adjlist[node][i].first;
            long long wx = adjlist[node][i].second;
            if (dist[nx] > dist[node] + wx) {
                dist[nx] = dist[node] + wx;
                S.insert(make_pair(dist[nx], nx));
            }
        }
    }

    if (!visited[dest])
        cout << "NO" << endl;
    else
        cout << "YES" << endl << dist[dest] << endl;

    return 0;
}
