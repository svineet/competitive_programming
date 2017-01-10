#include <bits/stdc++.h>
using namespace std;

int levels[4000];
bool visited[4000];
vector<int> adjlist[4000];
queue< pair<int, int> > Q;

int main() {
    int n, m; cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    for (int i=0; i<4000; i++) {
        levels[i] = 0; visited[i] = false;
    }

    int start = 1, target = 1; cin >> start >> target;
    
    if (start<=0 || target<=0 || start>n || target>n) {
        cout << 0 << endl;
        return 0;
    }

    // Node, level
    Q.push(make_pair(start, 0));
    visited[start] = true; levels[start] = 0;
    while (!Q.empty()) {
        pair<int, int> vertex = Q.front();
        int node = vertex.first, level = vertex.second;
        Q.pop();

        int len = adjlist[node].size();
        for (int i=0; i<len; i++) {
            int nx = adjlist[node][i];
            if (!visited[nx]) {
                visited[nx] = true;
                levels[nx] = level+1;
                Q.push(make_pair(nx, level+1));
            }
        }
    }

    if (!visited[target])
        cout << 0 << endl;
    else if (start<=0 || start>n || target>n || target<=0)
        cout << 0 << endl;
    else
        cout << levels[target] << endl;

    return 0;
}
