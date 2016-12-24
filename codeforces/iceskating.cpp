#include <bits/stdc++.h>
using namespace std;

vector<int> adjlist[101];
int visited[101];

void DFS(int node) {
    int len = adjlist[node].size();
    for (int i=0; i<len; i++) {
        int next = adjlist[node][i];
        if (!visited[next]) {
            visited[next] = 1;
            DFS(next);
        }
    }
}

int main() {
    int n; cin >> n;
    pair<int, int> heaps[n];
    for (int i=0; i<n; i++) {
        cin >> heaps[i].first >> heaps[i].second;
    }

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (heaps[i].first == heaps[j].first || heaps[i].second == heaps[j].second) {
                // Can skate from one to the other
                adjlist[i].push_back(j);
                adjlist[j].push_back(i);
            }
        }
    }

    int components = 0;
    for (int i=0; i<n; i++) {
        if (!visited[i]) {
            components++;
            visited[i] = 1;
            DFS(i);
        }
    }

    cout << components-1 << endl;

    return 0;
}
