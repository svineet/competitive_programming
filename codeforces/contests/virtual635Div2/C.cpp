#include <bits/stdc++.h>
using namespace std;

int n, k; 
vector<int> adj[210000+1];
long long depths[210000+1];
int parent[210000+1];
int descendants[210000+1];


void dfs(int node, int depth, int prev) {
    parent[node] = prev;
    depths[node] = depth;

    // cout << "Current: " << node << " ; Prev: " << prev << endl;
    descendants[node] = 0;
    for (int next: adj[node]) {
        // cout << "  Next: " << next << endl;
        if (next != prev) {
            dfs(next, depth+1, node);

            descendants[node] += descendants[next]+1;
        }
    }

    // cout << "Node " << node << "; Descendants " << descendants[node] << endl;
}


int main(int argc, char **argv) {
    cin >> n >> k;
    for (int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b;

        adj[a].push_back(b); adj[b].push_back(a);
        depths[i+1] = 0;
    }

    // Idea: Start at the root, mark depths of the nodes
    // Take sum of the k largest depths
    dfs(1, 0, -1);

    /*
        for (int i=1; i<=n; i++)
            cout << i << " " << depths[i] << endl;
    */

    // Pick the tourist cities
    int tourists = n - k;

    long long result = 0;
    int happiness[n+1];
    for (int i=1; i<=n; i++) {
        happiness[i] = descendants[i] - depths[i];
    }
    sort (happiness+1, happiness+n+1, greater<int>());

    for (int i=1; i<=tourists; i++) result += happiness[i];

    cout << result << endl;

    return 0;
}
