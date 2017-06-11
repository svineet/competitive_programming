/*
ID: saivine1
PROG: wormhole
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> arr[100];
int adjm[100][100];
int color[100];

bool DFS(int node, int parent) {
    color[node] = 1;
    // Exploring right now
    for (int i=0; i<n; i++) {
        if (i==parent || i==node) continue;
        bool conn = arr[node].second == arr[i].second &&
                    arr[node].first < arr[i].first;
        conn = conn || adjm[node][i]==1;

        if (conn && color[i] == 1) {
            // A node that was being explored is
            // touched. Back edge, cycle.
            return true;
        } else if (conn && color[i] == 0) {
            if (DFS(i, node)) return true;
        }

        if (color[i] == 2 && conn) {
            for (int i=0; i<n; i++) {
                cout << arr[i].first << " " << arr[i].second << endl;
            }
            cout << "----" << endl;
        }
    }
    color[node] = 2;

    // No cycles.
    return false;
}

bool cyclic() {
    for (int i=0; i<n; i++) color[i] = 0;
    for (int i=0; i<n; i++) {
        if (color[i] == 0) {
            if (DFS(i, -1)) return true;
        }
    }
    return false;
}

long long solve(int i) {
    if (i==n) {
        if (cyclic()) {
            for (int i=0; i<n; i++) {
                cout << arr[i].first << " " << arr[i].second << endl;
            }
            return 1;
        } else {
            return 0;
        }
    }

    // Replace i+1 with some element
    // from arr[i+1..n-1]
    // And recurse.
    long long res = 0;
    for (int j=i+1; j<n; j++) {
        swap(arr[j], arr[i+1]);
        adjm[i][i+1] = 1;
        adjm[i+1][i] = 1;

        res += solve(i+2);

        swap(arr[j], arr[i+1]);
        adjm[i][i+1] = 0;
        adjm[i+1][i] = 0;
    }
    return res;
}

int main() {
    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    cout << solve(0) << endl;

    return 0;
}
