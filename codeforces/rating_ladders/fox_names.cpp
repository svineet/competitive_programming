#include <bits/stdc++.h>
using namespace std;

bool CycleDFS(int node, vector<int> adj[], int color[]) {
    color[node] = 1;
    for (int nx: adj[node]) {
        if (color[nx] == 0) {
            if (CycleDFS(nx, adj, color)) return true;
        } else if (color[nx] == 1) {
            return true;
        }
    }
    color[node] = 2;
    return false;
}

void TopoDFS(int node, vector<int> adj[], stack<int> *S,
             bool visited[]) {
    visited[node] = true;
    for (int nx: adj[node]) {
        if (!visited[nx]) {
            TopoDFS(nx, adj, S, visited);
        }
    }
    S->push(node);
}

int main() {
    int n; cin >> n;
    string str[n];
    for (int i=0; i<n; i++) {
        cin >> str[i];
    }

    vector<int> adj[26];
    bool fukt = false;
    for (int i=0; i<n-1; i++) {
        int l1 = str[i].length(),
            l2 = str[i+1].length();

        int dex = -1;
        for (int j=0; j<min(l1, l2); j++) {
            if (str[i][j] != str[i+1][j]) {
                dex = j; break;
            }
        }

        if (dex == -1) {
            if (l1 > l2) {
                fukt = true; break;
            }
        } else {
            adj[int(str[i][dex]-'a')].push_back(int(str[i+1][dex]-'a'));
        }
    }
 
    // Detect cycles.
    int color[26];
    fill (color, color+26, 0);
    for (int i=0; i<26; i++) {
        if (color[i] == 0) {
            fukt = fukt || CycleDFS(i, adj, color);
        }
    }

    bool visited[26];
    fill (visited, visited+26, false);
    stack<int> S;
    for (int i=0; i<26; i++) {
        if (!visited[i]) {
            TopoDFS(i, adj, &S, visited);
        }
    }

    if (fukt) {
        cout << "Impossible" << endl;
        return 0;
    }

    list<char> things;
    while (!S.empty()) {
        things.push_back(char('a'+S.top()));
        S.pop();
    }

    for (char node: things)
        cout << node;
    cout << endl;

    return 0;
}
