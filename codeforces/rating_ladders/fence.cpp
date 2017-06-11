#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int height[n];
    for (int i=0; i<n; i++)
        cin >> height[i];

    int lptr = 0;
    int rptr = k-1;
    int ch = 0;
    for (int i=0; i<=rptr; i++)
        ch += height[i];

    int mn = ch;
    int best = 0;
    rptr++; lptr++;
    while (rptr < n) {
        ch += height[rptr];
        ch -= height[lptr-1];

        if (ch < mn) {
            best = lptr;
            mn = ch;
        }

        rptr++; lptr++;
    }
    cout << best+1 << endl;

    return 0;
}
