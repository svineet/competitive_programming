#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n; cin >> n;
    string str; cin >> str;

    int fa, fg, fc, ft;
    fa = fg = fc = ft = 0;

    for (int i=0; i<n; i++) {
        if (str[i] == 'A')
            fa++;
        if (str[i] == 'G')
            fg++;
        if (str[i] == 'C')
            fc++;
        if (str[i] == 'T')
            ft++;
    }

    int array[4] = {fa, fg, fc, ft};
    sort (array, array+4, greater<int>());
    int mx = array[0];
    int mxnum = 1;
    for (int i=1; i<4; i++) {
        if (array[i] == mx) mxnum++;
    }

    long long cnt = 1;
    for (int i=1; i<=n; i++) {
        cnt *= mxnum;
        cnt %= MOD;
    }

    cout << cnt << endl;

    return 0;
}
