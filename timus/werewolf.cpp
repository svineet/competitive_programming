#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adjlist[1010];
vector<int> adjtrans[1010];
bool notsuspect[1010];

void DFS(int node) {
    int len = adjlist[node].size();
    for (int i=0; i<len; i++) {
        int nx = adjlist[node][i];
        notsuspect[nx] = true;
        DFS(nx);
    }
}

void DFSTranspose(int node) {
    int len = adjtrans[node].size();
    for (int i=0; i<len; i++) {
        int nx = adjtrans[node][i];
        notsuspect[nx] = true;
        DFSTranspose(nx);
    }
}

int main() {
    cin >> n;
    string inp;
    while (true) {
        cin >> inp;
        if (inp == "BLOOD") break;
        int a = atoi(inp.c_str());
        int b; cin >> b;
        adjlist[a].push_back(b);
        adjtrans[b].push_back(a);
    }

    int victim;
    while (cin >> victim) {
        notsuspect[victim] = true;
        DFS(victim); DFSTranspose(victim);
    }

    int count = 0;
    for (int i=1; i<=n; i++) {
        if (!notsuspect[i]) {
            cout << i << " ";
            count++;
        }
    }
    if (count==0) {
        cout << 0 << endl;
    } else {
        cout << endl;
    }

    return 0;
}
