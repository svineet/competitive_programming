#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string str; cin >> str;
    queue<int> dpos, rpos;
    for (int i=0; i<n; i++) {
        if (str[i] == 'D')
            dpos.push(i);
        else
            rpos.push(i);
    }

    while (!(dpos.empty() || rpos.empty())) {
        int r = rpos.front(),
            d = dpos.front();
        if (d<r) {
            dpos.pop(); dpos.push(d+n);
            rpos.pop();
        } else {
            rpos.pop(); rpos.push(r+n);
            dpos.pop();
        }
    }
    if (dpos.empty())
        cout << "R";
    else
        cout << "D";
    cout << endl;

    return 0;
}
