#include <bits/stdc++.h>
using namespace std;

int n, m; 
vector<int> adjlist[305];

int main() {
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    return 0;
}
