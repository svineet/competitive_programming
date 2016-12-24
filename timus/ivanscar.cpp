#include <bits/stdc++.h>
using namespace std;

#define mp(i, j) make_pair(i, j)

int main() {
    int n, m; cin >> n >> m;
    int dist[n+1][2];
    bool visited[n+1][2];
    vector<int> uphill[n+1], downhill[n+1];
    for (int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        uphill[a].push_back(b);
        downhill[b].push_back(a);
    }
    int start, end; cin >> start >> end;
    for (int i=1; i<=n; i++) {
        dist[i][0] = dist[i][1] = 1e8;
        visited[i][0] = visited[i][1] = false;
    }
    dist[start][0] = dist[start][1] = 0;

    set< pair<int, pair<int, int> > > S;
    S.insert(make_pair(0, make_pair(start, 0)));
    S.insert(make_pair(0, make_pair(start, 1)));
    while (!S.empty()) {
        int node = S.begin()->second.first;
        int hill = S.begin()->second.second;
        S.erase(S.begin());

        if (visited[node][hill]) continue;
        visited[node][hill] = true;
        //cout << node << " " << hill << endl;

        int upcost = hill==0?0:1;
        int downcost = hill==0?1:0;

        int len = uphill[node].size(); 
        for (int i=0; i<len; i++) {
            int nx = uphill[node][i];
            if (dist[nx][0] > dist[node][hill]+upcost) {
                dist[nx][0] = dist[node][hill]+upcost;
                S.insert(make_pair(dist[nx][0], make_pair(nx, 0)));
            }
        }
        len = downhill[node].size();
        for (int i=0; i<len; i++) {
            int nx = downhill[node][i];
            if (dist[nx][1] > dist[node][hill]+downcost) {
                dist[nx][1] = dist[node][hill]+downcost;
                S.insert(make_pair(dist[nx][1], make_pair(nx, 1)));
            }
        }
    }
    cout << min(dist[end][0], dist[end][1]) << endl;

    return 0;
}
