#include <bits/stdc++.h>
using namespace std;

int n, m, k; 
vector<int> adjlist[1010];
int adjmatrix[1010][1010];
int govnodes[1010];
vector<int> comp[1010];
bool visited[1010];

void DFS(int node, int cnum) {
    int len = adjlist[node].size();
    for (int i=0; i<len; i++) {
        int nx = adjlist[node][i];
        if (!visited[nx]) {
            visited[nx] = true;
            comp[cnum].push_back(nx);
            DFS(nx, cnum);
        }
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i=0; i<k; i++)
        cin >> govnodes[i];

    for (int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
        adjmatrix[a][b] = 1;
        adjmatrix[b][a] = 1;
    }

    long long maxcompers = 0;
    for (int i=0; i<k; i++) {
        visited[govnodes[i]] = true;
        comp[i].push_back(govnodes[i]);
        DFS(govnodes[i], i);
        int len = comp[i].size();
        if (len>maxcompers)
            maxcompers = len;
    }

    long long count = 0;
    int uncon = 0;
    for (int i=1; i<=n; i++) {
        if (!visited[i]) {
            uncon++;
            count += maxcompers;
        }
        // Stray nodes
        // will be attached to most nodes
        // component.
    }

    if (uncon>2) {
        // Connect the ungoverned nodes to each
        // other as well as the max component
        // graph nodes
        count += uncon*(uncon-1)/2;
    }

    for (int i=0; i<k; i++) {
        long long len = comp[i].size();
        count += len*(len-1)/2;
    }

    count -= m;
    // Remove already counted nodes.
    cout << count << endl;

    return 0;
}
