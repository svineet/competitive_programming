#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> adjlist[n+1];
    int color[n+1];
    for (int i=1; i<=n; i++) {
        color[i] = -1;
        int dest; cin >> dest;
        while (dest != 0) {
            adjlist[i].push_back(dest);
            adjlist[dest].push_back(i);
            cin >> dest;
        }
    }

    queue<int> Q;
    color[1] = 0;
    Q.push(1);
    bool fukt = false;
    while (!Q.empty() && !fukt) {
        int node = Q.front();
        Q.pop();
        int len = adjlist[node].size();
        for (int i=0; i<len; i++) {
            int nx = adjlist[node][i];
            if (color[nx] == -1) {
                color[nx] = 1-color[node];
                Q.push(nx);
            } else if (color[nx] != 1-color[node]) {
                fukt = true; break;
            }
        }
    }
    if (fukt) {
        cout << -1 << endl;
    } else {
        for (int i=1; i<=n; i++)
            cout << color[i];
        cout << endl;
    }

    return 0;
}
