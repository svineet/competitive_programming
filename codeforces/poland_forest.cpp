#include <bits/stdc++.h>
using namespace std;

void DFS(int node, vector<int> adjlist[], bool visited[]) {
    for (auto next: adjlist[node]) {
        if (visited[next]) continue;

        visited[next] = true;
        DFS(next, adjlist, visited);
    }
}

int main() {
    int n; cin >> n;
    vector<int> adjlist[n+1];
    for (int i=1; i<=n; i++) {
        int a; cin >> a;
        adjlist[a].push_back(i);
        adjlist[i].push_back(a);
        // These two are transitives.
    }

    bool visited[n+1];
    fill (visited, visited+n+1, false);
    int comps = 0;
    for (int i=1; i<=n; i++) {
        if (!visited[i]) {
            comps++;
            visited[i] = true;
            DFS(i, adjlist, visited);
        }
    }

    cout << comps << endl;

    return 0;
}
