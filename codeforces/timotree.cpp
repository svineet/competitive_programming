#include <bits/stdc++.h>
using namespace std;

int n;
int color[200000];
bool homo[200000];
vector<int> adjlist[200000];

void Homo(int node, int parent) {
    int len = adjlist[node].size();
    homo[node] = true;
    int pdex = -1;
    for (int i=0; i<len; i++) {
        int nx = adjlist[node][i];
        if (nx != parent) {
            Homo(nx, node);
            homo[node] = homo[node] && homo[nx] && color[nx] == color[node];
            // Same coloured homogeneous
            // subtrees get stuck together.
        } else {
            pdex = i;
        }
    }

    if (pdex != -1) {
        vector<int>::iterator iter = adjlist[node].begin();
        while (pdex != 0) {
            iter++; pdex--;
        }
        adjlist[node].erase(pdex);
        // Make it a DAG.
    }
}

bool DFS(int node, int parent, bool path_homo) {
    int len = adjlist[node].size();
    bool all_homo = true;
    for (int i=0; i<len; i++) {
        int nx = adjlist[node][i];
        all_homo = all_homo && homo[nx];
    }

    if (all_homo) {
        // Holy crap, it's what we've been looking for!
        cout << "YES" << endl;
        cout << node << endl;
        return true;
    }

    if (len == 0) return path_homo;
    if (len == 1) {
        return homo[adjlist[node][0]] && path_homo;
    }
}

bool comp(int a, int b) {
    return color[a] < color[b];
}

int main() {
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    for (int i=1; i<=n; i++)
        cin >> color[i];

    color[0] = color[1];
    // For DFS magic.

    for (int i=1; i<=n; i++) {
        sort (adjlist[i].begin(), adjlist[i].end(),
              comp);
    }

    Homo(1, 0);
    if (!DFS(1, 0, true)) {
        cout << "NO" << endl;
    }

    return 0;
}
