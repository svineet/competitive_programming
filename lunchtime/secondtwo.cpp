#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector< vector<int> > counties(m, vector<int>(0));
    int dehati_counties[n];
    for (int i=0; i<n; i++) {
        int temp; cin >> temp;
        counties[temp-1].push_back(i);
        dehati_counties[i] = temp-1;
    }

    vector< vector<int> > adjlist(n, vector<int>(0));
    for (int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    /*for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/

    int q; cin >> q;
    for (int cs=0; cs<q; cs++) {
        int ca, cb; cin >> cb >> ca;
        ca--; cb--;
        for (int i=0; i<counties[ca].size(); i++) {
            int cityi = counties[ca][i];

            int visited[n];
            for (int i=0; i<n; i++) {
                visited[i] = 0;
            }
            visited[cityi] = 1;

            int curlevel = 0;
            vector<int> frontier;
            frontier.push_back(cityi);
            while (!frontier.empty()) {
                vector<int> next(0);
                for (int j=0; j<frontier.length(); j++) {
                    int node = frontier[i];
                    for (int j=
                }

                curlevel++;
                frontier = next;
            }
        }
        cout << mindist << endl;
    }

    return 0;
}
