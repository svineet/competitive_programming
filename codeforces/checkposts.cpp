#include <bits/stdc++.h>
using namespace std;

int n; 
long long times;
long long runmin = 1e8;
vector<int> adjlist[100005];
vector<int> transpose[100005];
stack<int> stk;
int visited[100005];
int component[100005];
long long cost[100005];

void DFS(int node) {
    //cout << "Explore " << node << endl;
    int len = adjlist[node].size();
    for (int i=0; i<len; i++) {
        int nx = adjlist[node][i];
        if (!visited[nx]) {
            visited[nx] = 1;
            DFS(nx);
        }
    }
    stk.push(node);
}

void DFSComponent(int node) {
    //cout << "Explore2 " << node << endl;
    if (cost[node-1]<runmin) {
        times = 1;
        runmin = cost[node-1];
    } else if (cost[node-1] == runmin) {
        times++;
    }
    //cout << runmin << endl;

    int len = transpose[node].size();
    for (int i=0; i<len; i++) {
        int nx = transpose[node][i];
        if (!component[nx]) {
            component[nx] = 1;
            DFSComponent(nx);
        }
    }
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> cost[i];
    }

    int m; cin >> m;
    for (int i=0; i<m; i++) {
        int s, d; cin >> s >> d;
        adjlist[s].push_back(d);
        transpose[d].push_back(s);
    }

    for (int i=1; i<=n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            DFS(i);
        }
    }

    long long totcost = 0;
    long long timesglob = 1;
    while (!stk.empty()) {
        int node = stk.top();
        stk.pop();
        if (!component[node]) {
            component[node] = 1;
            times = 1; runmin = 1e10;
            DFSComponent(node);
            times %= (int)1e9+7;
            timesglob *= times;
            timesglob %= (int)1e9+7;
            totcost += runmin;
        }
    }
    cout << totcost << " " << timesglob << endl;

    return 0;
}
