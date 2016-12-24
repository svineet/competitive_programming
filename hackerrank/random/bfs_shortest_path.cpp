#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main () {
    int q; cin >> q;
    for (int cs=0; cs<q; cs++) {
        int n, m; cin >> n >> m;
        vector<int> adjlist[n] = {vector<int>(0)};
        for (int i=0; i<m; i++) {
            int a, b; cin >> a >> b;
            a--; b--;
            adjlist[a].push_back(b);
            adjlist[b].push_back(a);
        }
        int start; cin >> start; start--;

        queue< pair<int, int> > Q;
        Q.push(make_pair(start, 0));
        int levels[n];
        for (int i=0; i<n; i++)
            levels[i] = -1;
        levels[start] = 0;
        while(!Q.empty()) {
            pair<int, int> info = Q.front(); Q.pop();
            int node = info.first; int curlevel = info.second;

            int adjsize = adjlist[node].size();
            for (int i=0; i<adjsize; i++) {
                if (levels[adjlist[node][i]] == -1) {
                    // Unvisited node found.
                    Q.push(make_pair(
                           adjlist[node][i], curlevel+1));
                    levels[adjlist[node][i]] = curlevel+1;
                }
            }
        }
        for (int i=0; i<n; i++) {
            if (i==start) continue;
            cout << (levels[i]==-1?-1:levels[i]*6) << " ";
        }
        cout << endl;
    }

    return 0;
}
