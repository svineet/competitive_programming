/*
ID: saivine1
PROG: beads
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int find_best(string str, int i, int n, char lchar, char rchar) {
    int j = i;
    while ((rchar == str[j] || str[j] == 'w')
            && j<2*n && j-i+1<=n) j++;
    j--;

    int j2 = i-1;
    while ((lchar == str[j2] || str[j2] == 'w')
            && j2>=0 && j-j2+1<=n) j2--;
    j2++;

    return (j-j2+1);
}

int main() {
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);

    int n; cin >> n;
    string str; cin >> str;
    str += str;

    int ans = 0;
    for (int i=1; i<2*n; i++) {
        int cands = 0;

        if (str[i-1] == 'w' && str[i] == 'w') {
            cands = max({find_best(str, i, n, 'r', 'r'),
                         find_best(str, i, n, 'r', 'w'),
                         find_best(str, i, n, 'w', 'r'),
                         find_best(str, i, n, 'w', 'r')});
        } else if (str[i] == 'w') {
            cands = max({find_best(str, i, n, str[i], 'r'),
                         find_best(str, i, n, str[i], 'w')});
        } else if (str[i-1] == 'w') {
            cands = max({find_best(str, i, n, 'r', str[i]),
                         find_best(str, i, n, 'w', str[i])});
        } else {
            cands = find_best(str, i, n, str[i-1], str[i]);
        }

        ans = max(ans, cands);
    }
    cout << ans << endl;

    return 0;
}
