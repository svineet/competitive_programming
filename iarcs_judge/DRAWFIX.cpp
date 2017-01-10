#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    pair<int, int> siruseri[n], navalur[n];
    for (int i=0; i<n; i++) {
        cin >> siruseri[i].first;
        siruseri[i].second = i+1;
    }

    int paired[n];
    bool pairn[n];
    for (int i=0; i<n; i++) {
        cin >> navalur[i].first;
        navalur[i].second = i+1;
        paired[i] = -1;
        pairn[i] = false;
    }

    sort (siruseri, siruseri+n);
    sort (navalur, navalur+n);

    int nptr = n-1;
    int i = 0;
    for (i=n-1; i>=0; i--) {
        if (nptr<0) break;
        while (navalur[nptr].first>=siruseri[i].first) {
            nptr--;
        }
        if (nptr<0) break;
        paired[siruseri[i].second] = navalur[nptr].second;
        pairn[nptr] = true;
        nptr--;
    }

    cout << n-i-1 << endl;
    nptr = 0;
    for (int i=0; i<n; i++) {
        if (paired[i] != -1) {
            cout << paired[i]+1 << endl;
        } else {
            while (pairn[nptr]) {
                nptr++;
            }
            cout << nptr+1 << endl;
            nptr++;
        }
    }
}
