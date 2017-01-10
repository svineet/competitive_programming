#include <bits/stdc++.h>
using namespace std;

queue< pair<int, int> > Q;

int main() {
    int n, m; cin >> n >> m;

    if (n == m) {
        cout << 0 << endl;
        return 0;
    }

    bool visited[100001] = {false};
    visited[n] = true;
    Q.push(make_pair(n, 0));
    int ans = 0;
    while (!Q.empty()) {
        int num = Q.front().first;
        int lvl = Q.front().second;
        Q.pop();
        if (num == m) {
            ans = lvl; break;
        }

        if (num>0 && !visited[num-1]) {
            visited[num-1] = true;
            Q.push(make_pair(num-1, lvl+1));
        }

        if (2*num<=100000 && !visited[2*num]) {
            visited[2*num] = true;
            Q.push(make_pair(num*2, lvl+1));
        }
    }

    cout << ans << endl;

    return 0;
}
