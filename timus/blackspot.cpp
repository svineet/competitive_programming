#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    vector< pair<int, double> > adjlist[n+1];
    pair<int, double> dist[n+1];
    int parent[n+1];
    bool visited[n+1];
    for (int i=1; i<=n; i++) {
        dist[i].first = 1e8;
        dist[i].second = 1.0;
        visited[i] = false;
    }

    int start, end;
    scanf("%d%d", &start, &end);

    for (int i=0; i<m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        int p___; scanf("%d", &p___);
        double p = p___/100.000;

        adjlist[a].push_back(make_pair(b, p));
        adjlist[b].push_back(make_pair(a, p));
    }

    set< pair< pair<int, double>,
               int > > S;
    // ( (number of islands seen,
    //    probability of meeting kraken on that route to kraken),
    //    node/island number
    // )
    dist[start] = make_pair(1, 0.0);
    parent[start] = -1;
    S.insert(make_pair(dist[start], start));
    while (!S.empty()) {
        int node = S.begin()->second;
        double p1 = dist[node].second;
        int pathw = dist[node].first;

        S.erase(S.begin());

        if (visited[node]) continue;
        visited[node] = true;

        int len = adjlist[node].size();
        for (int i=0; i<len; i++) {
            int nx = adjlist[node][i].first;
            double p2 = adjlist[node][i].second;
            int distnx = pathw+1;
            double ptot = 1 - (1-p1)*(1-p2);
            // Probability of finding kraken on this whole route
            // given P(first route) and P(second route)
            // is 1 - P(not finding on both)
            // P(not finding) = (1 - P(first))(1 - P(second))
            // Thus formula is derived.
            if (dist[nx] > make_pair(distnx, ptot)) {
                dist[nx] = make_pair(distnx, ptot);
                parent[nx] = node;
                S.insert(make_pair(dist[nx], nx));
            }
        }
    }

    assert (visited[end]);
    printf("%d %.7f\n", dist[end].first, dist[end].second);

    stack<int> path;
    int cur = end;
    while (cur != -1) {
        path.push(cur);
        cur = parent[cur];
    }

    while (!path.empty()) {
        printf("%d ", path.top());
        path.pop();
    }
    printf("\n");

    return 0;
}
