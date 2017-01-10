#include <bits/stdc++.h>
using namespace std;

int n;
long long pls[1000000];
long long dp[1000000];
// Best sum achievable from sons
// -1 if only one son exists
long long subsum[1000000];
long long bestsub[1000000];
long long globmax;
long long tempsort[1000000];
// Sum of whole subtree
vector<int> adjlist[1000000];

void DFS(int node, int parent) {
    subsum[node] = pls[node];
    bestsub[node] = -1e10;
    int len = adjlist[node].size();
    for (int i=0; i<len; i++) {
        int nx = adjlist[node][i];
        if (nx == parent) continue;
        DFS(nx, node);
        subsum[node] += subsum[nx];
        bestsub[node] = max(bestsub[node], max(bestsub[nx], subsum[nx]));
    }
    bestsub[node] = max(subsum[node], bestsub[node]);
    //cout << node << " " << bestsub[node] << endl;
}

void DPTree(int node, int parent) {
    long long cursum = -1e10;
    // Assume impossible
    int len = adjlist[node].size();
    int tempdex = 0;
    for (int i=0; i<len; i++) {
        int nx = adjlist[node][i];
        if (nx != parent) {
            tempsort[tempdex] = bestsub[nx];
            tempdex++;
        }
    }
    sort (tempsort, tempsort+tempdex);
    if (tempdex>1) {
        // Means that # children is more than 1
        cursum = max(cursum, tempsort[tempdex-1]+tempsort[tempdex-2]);
        cursum = max(cursum, subsum[node]);
        // Take the whole subtree starting from one nx
        // and the tree from node going the other direction.
    }
    globmax = max(globmax, cursum);

    for (int i=0; i<len; i++) {
        int nx = adjlist[node][i];
        if (nx != parent) {
            DPTree(nx, node);
        }
    }
}

int main() {
    cin >> n;
    globmax = -1e10;
 
    // ALSO IMPOSSIBLE IF
    // ONLY ONE SUBTREE IS FORMED

    for (int i=1; i<=n; i++)
        cin >> pls[i];
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    
    DFS(1, -1);
    DPTree(1, -1);
    if (globmax == -1e10)
        cout << "Impossible" << endl;
    else
        cout << globmax << endl;

    return 0;
}
