#include <bits/stdc++.h>
using namespace std;

int n; string array[105];
vector<int> adjlist[105];
int dist[105]; bool visited[105];
stack<int> stk;
int sorted[105];

void TopoRecursive(int node) {
    int len = adjlist[node].size();
    for (int i=0; i<len; i++) {
        if (!visited[adjlist[node][i]]) {
            visited[adjlist[node][i]] = true;
            TopoRecursive(adjlist[node][i]);
        }
    }

    stk.push(node);
}

void TopologicalSort() {
    for (int i=0; i<n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            TopoRecursive(i);
        }
    }

    int i = 0;
    while (!stk.empty()) {
        int node = stk.top(); stk.pop();
        sorted[i] = node;
        i++;
    }
}

bool connected(int i, int j) {
    int diff = array[i].length()-array[j].length();
    int faults = 0;
    int l1 = array[i].length(),
        l2 = array[j].length();

    if (diff == 1) {
        int lptr = 0, rptr = 0;
        while (lptr<l1 && rptr<l2) {
            if (array[i][lptr] == array[j][rptr]) {
                lptr++; rptr++;
            } else {
                faults++; lptr++;
            }
        }

        if (lptr == l1-1 && rptr == l2) return true;
        // Prefix
    } else if (diff == 0) {
        for (int k=0; k<l1; k++) {
            if (array[i][k] != array[j][k]) {
                if (array[i][k] < array[j][k]) {
                    faults++;
                    bool found = false;
                    for (int x=k+1; x<l1; x++) {
                        if (array[i][x] == array[j][k]) {
                            found = true; break;
                        }
                    }
                    if (!found) return false;
                } else {
                    return false;
                }
            }
        }
    }

    return (faults==1);
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (connected(i, j)) {
                adjlist[i].push_back(j);
            } else if (connected(j, i)) {
                adjlist[j].push_back(i);
            }
        }
    }

    /*for (int i=0; i<n; i++) {
        cout << i << ": ";
        int len = adjlist[i].size();
        for (int j=0; j<len; j++) {
            cout << adjlist[i][j] << " ";
        }
        cout << endl;
    }*/

    TopologicalSort();

    int longest = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            dist[j] = -1e8;
        dist[i] = 0;

        for (int j=0; j<n; j++) {
            int node = sorted[j];
            int len = adjlist[node].size();
            for (int k=0; k<len; k++) {
                int nx = adjlist[node][k];
                if (dist[nx]<dist[node]+1)
                    dist[nx] = dist[node] + 1;
            }
        }

        /*for (int i=0; i<n; i++)
            cout << dist[i] << " ";
        cout << endl;*/

        int best = *max_element(dist, dist+n);
        longest = max(longest, best);
    }

    if (longest < 0) {
        cout << 0 << endl;
    } else if (longest == 0) {
        cout << 0 << endl;
    } else {
        cout << longest+1 << endl;
    }

    return 0;
}
