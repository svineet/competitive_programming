#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    long long h[n];
    for (int i=0; i<n; i++)
        cin >> h[i];

    long long last = 0;
    long long lh = 0;
    int m; cin >> m;
    for (int i=0; i<m; i++) {
        long long wide, height;
        cin >> wide >> height;
        last = max(last+lh, h[wide-1]);
        cout << last << "\n";
        lh = height;
    }

    return 0;
}
