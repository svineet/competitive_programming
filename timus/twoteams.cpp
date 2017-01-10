#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> adjlist[n+1];
    int color[n+1];
    for (int i=1; i<=n; i++) {
        color[i] = 0;
        int dest;
        do {
            cin >> dest;
            adjlist[i].push_back(dest);
        } while (dest != 0);
    }

    for (int i=1; i<=n; i++) {
        if (color[i] == 0) {
            color[i] = 1;
            queue<int> Q;
            Q.push(i);
            while (!Q.empty()) {
                int node = Q.front();
                Q.pop();
                int len = adjlist[node].size();
                for (int i=0; i<len; i++) {
                    int nx = adjlist[node][i];
                    if (color[nx] == 0) {
                        color[nx] = (color[node] == 1? 2: 1);
                        Q.push(nx);
                    }
                }
            }
        }
        //cout << color[i] << endl;
    }

    bool fukt = false;
    vector<int> c_one;
    for (int i=1; i<=n; i++) {
        if (color[i] == 1) c_one.push_back(i);
        int need = (color[i] == 1? 2: 1);
        int len = adjlist[i].size();
        bool okay = false;
        for (int j=0; j<len; j++) {
            if (color[adjlist[i][j]] == need) {
                okay = true; break;
            }
        }

        if (!okay) {
            fukt = true; break;
        }
    }

    if (fukt) {
        cout << 0 << endl;
    } else {
        int len = c_one.size();
        cout << c_one.size() << endl;
        for (int i=0; i<len; i++) {
            cout << c_one[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
