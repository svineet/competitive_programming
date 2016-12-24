#include <bits/stdc++.h>
using namespace std;

int n, m; 
bool in_bounds(int i, int j) {
    return i>=0 && i<n && j>=0 && j<m;
}

int main() {
    cin >> n >> m;
    char mat[n][m][4];
    int dist[n][m];
    bool visited[n][m];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            for (int k=0; k<4; k++) {
                cin >> mat[i][j][k];
            }
            dist[i][j] = 1e8;
            visited[i][j] = false;
        }
    }

    set< pair<int, int> > S;
    dist[0][0] = 0;
    S.insert(make_pair(0, 0));
    while (!S.empty()) {
        int nodeid = S.begin()->second;
        S.erase(S.begin());

        int i = nodeid/m;
        int j = nodeid%m;
        if (visited[i][j]) continue;
        visited[i][j] = true;
        /*cout << i << " " << j << endl;
        for (set< pair<int, int> >::iterator iter = S.begin();
             iter != S.end();
             iter++) {
            cout << iter->second/m << ";" << iter->second%m << ";";
            cout << iter->first << " ";
        }
        cout << endl;*/

        int ndist;
        if (in_bounds(i-1, j)) {
            char need = mat[i-1][j][2];
            int pos = -1;
            for (int k=0; k<4; k++) {
                if (mat[i][j][k] == need)
                    pos = k;
            }
            ndist = pos==0?0:4-pos;
            dist[i-1][j] = min(dist[i-1][j],
                               dist[i][j]+ndist);
            S.insert(make_pair(dist[i-1][j],
                               (i-1)*m + j));
        }

        if (in_bounds(i+1, j)) {
            char need = mat[i+1][j][0];
            int pos = -1;
            for (int k=0; k<4; k++) {
                if (mat[i][j][k] == need)
                    pos = k;
            }
            ndist = (2-pos>=0?2-pos:6-pos);
            dist[i+1][j] = min(dist[i+1][j],
                               dist[i][j]+ndist);
            S.insert(make_pair(dist[i+1][j],
                               (i+1)*m + j));
        }

        if (in_bounds(i, j-1)) {
            char need = mat[i][j-1][1];
            int pos = -1;
            for (int k=0; k<4; k++) {
                if (mat[i][j][k] == need)
                    pos = k;
            }
            ndist = 3-pos;
            dist[i][j-1] = min(dist[i][j-1],
                               dist[i][j]+ndist);
            S.insert(make_pair(dist[i][j-1],
                               i*m + j-1));
        }

        if (in_bounds(i, j+1)) {
            char need = mat[i][j+1][3];
            int pos = -1;
            for (int k=0; k<4; k++) {
                if (mat[i][j][k] == need)
                    pos = k;
            }
            ndist = (1-pos>=0?1-pos:5-pos);
            dist[i][j+1] = min(dist[i][j+1],
                               dist[i][j]+ndist);
            S.insert(make_pair(dist[i][j+1],
                               i*m + j+1));
        }
    }

    /*for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++)
            cout << dist[i][j] << " ";
        cout << endl;
    }*/
    cout << dist[n-1][m-1] << endl;

    return 0;
}
