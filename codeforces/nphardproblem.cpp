#include <bits/stdc++.h>
using namespace std;

int n, m; 
int color[100011];
vector<int> adjlist[100011+1];

bool DFS(int node) {
    int len = adjlist[node].size();
    for (int i=0; i<len; i++) {
        int nx = adjlist[node][i];
        if (color[nx] != 0) {
            if (color[nx] != 3-color[node])
                return false;
        } else {
            color[nx] = 3-color[node];
            bool okay = DFS(nx);
            if (!okay) return false;
        }
    }

    return true;
}

int main() {
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    bool fukt = false;
    // 1 and 2 are the only colors available;
    for (int i=1; i<=n && !fukt; i++) {
        if (color[i] == 0) {
            color[i] = 1;
            fukt = !DFS(i);
        }
    }

    if (fukt) {
        cout << -1 << endl;
    } else {
        vector<int> ones, twos;
        ones.reserve(n/2);
        twos.reserve(n/2);
        for (int i=1; i<=n; i++) {
            if (color[i] == 1)
                ones.push_back(i);
            else
                twos.push_back(i);
        }

        int len = ones.size();
        cout << len << endl;
        for (int i=0; i<len; i++)
            cout << ones[i] << " ";
        cout << endl;
        
        int len2 = twos.size();
        cout << len2 << endl;
        for (int i=0; i<len2; i++) {
            cout << twos[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
