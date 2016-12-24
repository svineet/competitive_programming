/*
 * Doesn't work.
 */

#include <bits/stdc++.h>
using namespace std;

int n; 
int levels[5001][5001];
vector<int> adjlist[6000+1];

void DFS(int node, int parent, int lvl, int subtree) {
    int len = adjlist[node].size();
    for (int i=0; i<len; i++) {
        int nx = adjlist[node][i];
        if (nx != parent) {
            levels[subtree][lvl+1]++;
            // Count nodes at each level.
            DFS(nx, node, lvl+1, subtree);
        }
    }
}

int main() {
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    long long cnt = 0;
    for (int i=1; i<=n; i++) {
        int len = adjlist[i].size();
        memset(levels, 0, sizeof(levels));
        for (int j=0; j<len; j++) {
            int nx = adjlist[i][j];
            levels[j][1] = 1;
            DFS(nx, i, 1, j);
        }

        bool okay = true;
        cout << "Node " << i << endl;
        for (int j=1; j<=n && okay; j++) {
            long long adder = 1;
            cout << "level: " << j << endl;
            for (int k=0; k<len; k++) {
                cout << "Subtree: " << k << " " << levels[k][j] << endl;
                adder *= levels[k][j];
                if (levels[k][j] == 0) okay = false;
            }
            // As soon as a zero is found
            // we know that there will
            // be only zeroes ahead
            // So no use continuing.
            cnt += adder;
        }
    }
    cout << cnt << endl;
}
