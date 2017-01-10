#include <bits/stdc++.h>
using namespace std;

vector<int> adjlist[1010];
bool visited[1010];
int verify[1010];
int indices[1010];

bool DFS(int node) {
    // All nodes on this path should be greater than
    // 'greater' in the verify array
    int len = adjlist[node].size();
    for (int i=0; i<len; i++) {
        int nx = adjlist[node][i];
        if (indices[nx] >= indices[node]) return false;
        if (!visited[nx]) {
            visited[nx] = true;
            if (!DFS(nx)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m; cin >> n >> m;
    for (int i=0; i<m; i++) {
        int x, y; cin >> x >> y;
        adjlist[y].push_back(x);
    }
    for (int i=0; i<n; i++) {
        cin >> verify[i];
        indices[verify[i]] = i;
        // Index where i-th numbered node
        // occurs
    }

    bool fukt = false;
    for (int i=n-1; i>=0; i--) {
        if (!visited[verify[i]]) {
            visited[verify[i]] = true;
            if (!DFS(verify[i])) {
                fukt = true; break;
            }
        }
    }
    if (fukt)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}
