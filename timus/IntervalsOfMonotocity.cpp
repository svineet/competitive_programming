#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    int n = b-a+1;
    int array[n];
    int dp[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }

    dp[0] = 1;
    int lastinc = 0,
        lastdec = 0;
    for (int i=1; i<n; i++) {
        if (array[i]<array[i-1]) {
            lastinc = i;
        } else if (array[i]>array[i-1]) {
            lastdec = i;
        }
        dp[i] = min((lastinc>0?dp[lastinc-1]:0)+1,
                    (lastdec>0?dp[lastdec-1]:0)+1);
    }
    cout << dp[n-1] << endl;

    return 0;
}
