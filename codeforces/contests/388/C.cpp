#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string str; cin >> str;
    bool rekt[n];
    stack<int> rpos, dpos;
    for (int i=n-1; i>=0; i--) {
        if (str[i] == 'R')
            rpos.push(i);
        else
            dpos.push(i);
        rekt[i] = false;
    }

    for (int j=0; j<5; j++) {
        for (int i=0; i<n; i++) {
            if (rekt[i]) continue;
            if (str[i] == 'D') {
                int rpop;
                if (rpos.empty())
                    break;
                else
                    rpop = rpos.top();
                rpos.pop();
                rekt[rpop] = true;
            } else {
                int dpop;
                if (dpos.empty())
                    break;
                else
                    dpop = dpos.top();
                dpos.pop();
                rekt[dpop] = true;
            }
        }
        if (rpos.empty() || dpos.empty()) break;
    }

    if (rpos.empty())
        cout << "D" << endl;
    else
        cout << "R" << endl;

    return 0;
}
