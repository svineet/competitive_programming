#include <bits/stdc++.h>
using namespace std;

int adjm[2500][2500];
vector<int> path;

int main() {
    int n; cin >> n;
    for (int i=1; i<=n; i++) {
        int m; cin >> m;
        for (int j=0; j<m; j++) {
            int k; cin >> k;
            adjm[i][k] = 1;
        }
    }

    path.push_back(1);
    if (adjm[1][2]) {
        path.push_back(2);
    } else {
        path.insert(path.begin(), 2);
    }

    for (int i=3; i<=n; i++) {
        // Try to include i-th vertex
        // in hamiltonian path
        int len = path.size();
        if (adjm[i][path[0]]) {
            path.insert(path.begin(), i);
        } else if (adjm[path[len-1]][i]) {
            // i-2 == number of vertices inserted-1
            // == last index for path vector
            path.push_back(i);
        } else {
            bool got = false;
            for (int j=0; j<len-1; j++) {
                // Find path[j], path[j+1]
                // such that path[j] connects to
                // i and i connects to path[j+1]
                if (adjm[path[j]][i] && adjm[i][path[j+1]]) {
                    path.insert(path.begin()+j+1, i);
                    got = true;
                    break;
                }
            }
            assert(got);
        }
    }

    cout << "YES" << endl;
    for (int i=0; i<n; i++) {
        cout << path[i] << " ";
        if (i<n-1) assert(adjm[path[i]][path[i+1]]);
    }
    cout << endl;

    return 0;
}
