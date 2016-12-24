#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b; cin >> a >> b;
    int alen = a.length(),
        blen = b.length();
    int sum[blen],
        isum[blen];
    for (int i=0; i<blen; i++) {
        isum[i] = (i>0?isum[i-1]:0);
        sum[i] = (i>0?sum[i-1]:0);
        if (b[i] == '0') {
            isum[i]++;
        } else {
            sum[i]++;
        }
        //cout << sum[i] << " " << isum[i] << endl;
    }

    long long total = 0;
    for (int i=0; i<alen; i++) {
        if (a[i] == '1') {
            total += isum[i+blen-alen]-(i>0?isum[i-1]:0);
        } else {
            total += sum[i+blen-alen]-(i>0?sum[i-1]:0);
        }
    }

    cout << total << endl;

    return 0;
}
