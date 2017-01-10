#include <bits/stdc++.h>
using namespace std;

struct Node {
    string name;
    int a, b, c;
};

int main() {
    int n; cin >> n;
    vector<int> adjlist[n+1];
    Node nodes[n+1];
    for (int i=1; i<=n; i++) {
        cin >> nodes[i].name >> nodes[i].a >> nodes[i].b >> nodes[i].c;
    }

    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            Node inod = nodes[i];
            Node jnod = nodes[j];
            if ((inod.a > jnod.a && inod.b > jnod.b) ||
                (inod.b > jnod.b && inod.c > jnod.c) ||
                (inod.c > jnod.c && inod.a > jnod.a)) {
                // i-th node defeats j-th node.
                adjlist[i].push_back(j);
            } else {
                adjlist[j].push_back(i);
            }
        }
    }

    bool rekt[n+1];
    for (int i=1; i<=n; i++) {
        // Try to hire other
        // players as goons to kill
        // everyone they can
        // and do this recursively.
        // If everyone else is rekt
        // then we kill our hired goons
        // and win.
        stack<int> S;
        memset(rekt, 0, sizeof(rekt));
        rekt[i] = true;
        S.push(i);
        while (!S.empty()) {
            int node = S.top(); S.pop();
            int len = adjlist[node].size();
            for (int j=0; j<len; j++) {
                // Goons rekt everyone
                // they can.
                int nx = adjlist[node][j];
                if (!rekt[nx]) {
                    rekt[nx] = true;
                    S.push(nx);
                }
            }
        }

        bool okay = true;
        for (int j=1; j<=n && okay; j++) {
            if (!rekt[j]) okay = false;
        }

        if (okay) cout << nodes[i].name << "\n";
    }
}
