#include <bits/stdc++.h>
using namespace std;

vector<int> adjlist[100011];
map<int, set<int> > neighbours;
int color[100011];
int visited[100011];

void DFS(int node) {
    int len = adjlist[node].size();
    set<int> nset = neighbours[color[node]];
    for (int i=0; i<len; i++) {
        nset.insert(k
    }
}

int main() {
    int n, m; cin >> n >> m;
    for (int i=0; i<n; i++)
        cin >> color[i];
    for (int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    
    visited[1] = 1;
    DFS(1);

    map<int, set<int> >::iterator iter;
    int best = -100,
        bsize = -100;
    for (iter = neighbours.begin();
         iter != neighbours.end();
         iter++) {
        if (iter->second.size() > bsize) {
            best = iter->first;
            bsize = iter->second.size();
        }
    }
    cout << best << endl;

    return 0;
}
