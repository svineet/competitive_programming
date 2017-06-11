#include <bits/stdc++.h>
using namespace std;

int main() {
    string str; cin >> str;
    int n = str.length();

    int pre[n];
    pre[0] = 0;
    // pre[i] = number of indices
    // in 0..i-1 such that a[i+1] == a[i];
    for (int i=1; i<n; i++) {
        pre[i] = (str[i] == str[i-1]?1:0)+
                 pre[i-1];
    }

    /* for (int i=0; i<n; i++)
        cout << pre[i] << " ";
    cout << endl; */

    int m; cin >> m;
    for (int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        cout << pre[b]-pre[a] << endl;
    }

    return 0;
}
