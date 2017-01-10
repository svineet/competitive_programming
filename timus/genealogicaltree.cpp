#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> adjlist[n+1];
    int indegree[n+1] = {0};
    for (int i=1; i<=n; i++) {
        int dest;
        cin >> dest;
        while (dest != 0) {
            adjlist[i].push_back(dest);
            indegree[dest]++;
            cin >> dest;
        }
    }

    vector<int> order; order.reserve(n);
    queue<int> Q;
    for (int i=1; i<=n; i++) {
        if (indegree[i] == 0)
            Q.push(i);
    }
    while (!Q.empty()) {
        int node = Q.front(); Q.pop();
        order.push_back(node);
        int len = adjlist[node].size();
        for (int i=0; i<len; i++) {
            int nx = adjlist[node][i];
            indegree[nx]--;
            assert (indegree[nx] >= 0);
            if (indegree[nx] == 0)
                Q.push(nx);
        }
    }

    for (int i=0; i<n; i++)
        cout << order[i] << " ";
    cout << endl;

    return 0;
}
