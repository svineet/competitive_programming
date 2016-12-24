#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int k; cin >> k;
    string str; cin >> str;
    int visited[n];

    int start = 0, end = 0;
    for (int i=0; i<n; i++) {
        visited[i] = 0;
        if (str[i] == 'G')
            start = i;
        if (str[i] == 'T')
            end = i;
    }

    stack<int> stk;
    stk.push(start);
    visited[start] = 1;
    while (!stk.empty()) {
        int node = stk.top();
        stk.pop();
        if (node-k>=0 && !visited[node-k] && str[node-k] != '#') {
            visited[node-k] = 1;
            stk.push(node-k);
        }
        if (node+k<n && !visited[node+k] && str[node+k] != '#') {
            visited[node+k] = 1;
            stk.push(node+k);
        }
    }

    if (visited[end])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
