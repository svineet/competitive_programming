#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int colcnt[n] = {0}, rowcnt[n] = {0};
    for (int i=0; i<n; i++) {
        string str; cin >> str;
        for (int j=0; j<n; j++) {
            if (str[j] == 'C') {
                colcnt[j]++;
                rowcnt[i]++;
            }
        }
    }

    long long cnt = 0;
    for (int i=0; i<n; i++) {
        cnt += colcnt[i]*(colcnt[i]-1)/2;
        cnt += rowcnt[i]*(rowcnt[i]-1)/2;
    }

    cout << cnt << endl;

    return 0;
}
