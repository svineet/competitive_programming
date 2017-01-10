#include <bits/stdc++.h>
using namespace std;

int want[100005], init[100005];
vector<int> adjlist[100005];
vector<int> flipped;
int flipcount[2];

void DFS(int node, int parent, int level) {
    int parity = level%2;
    bool satisfied = (want[node]==init[node]);
    //cout << node << endl;
    //cout << want[node] << " " << init[node] << endl;
    if (flipcount[parity]%2!=0) {
        satisfied = !satisfied;
    }

    int len = adjlist[node].size();

    if (!satisfied) {
        flipped.push_back(node);
        flipcount[parity]++;
    }

    for (int i=0; i<len; i++) {
        if (adjlist[node][i] == parent) continue;
        DFS(adjlist[node][i], node, level+1);
    }

    if (!satisfied) flipcount[parity]--;
    // Backtrack

    return;
}

int main() {
    flipped.clear();
    int n; cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    for (int i=0; i<n; i++) cin >> init[i+1];
    for (int i=0; i<n; i++) cin >> want[i+1];

    DFS(1, -1, 0);

    int len = flipped.size();
    cout << len << endl;
    for (int i=0; i<len; i++) {
        cout << flipped[i] << endl;
    }
}
