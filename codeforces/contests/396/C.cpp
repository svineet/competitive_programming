#include <bits/stdc++.h>
using namespace std;

int durr(char a) {
    return int(a-'a');
}

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    string str; cin >> str;
    int limit[26];
    for (int i=0; i<26; i++)
        cin >> limit[i];

    int cur[26];
    int dp1[n], dp2[n], dp3[n];
    // Number of ways,
    // Max length of substring in splitting,
    // Min split.

    dp1[0] = 1;
    dp2[0] = 1;
    dp3[0] = 1;
    for (int i=1; i<n; i++) {
        for (int j=0; j<26; j++)
            cur[j] = 0;

        dp1[i] = 0;
        dp2[i] = 1;
        dp3[i] = i+1;
        for (int j=i; j>=0; j--) {
            cur[durr(str[j])] = 1;
            bool cont = true;
            for (int k=0; k<26; k++) {
                if (cur[k] == 1 && i-j+1 > limit[k])
                    cont = false;
            }
            if (!cont) break;

            dp1[i] += (j>0?dp1[j-1]:1);
            dp1[i] %= MOD;
            dp2[i] = i-j+1;
            dp3[i] = min(dp3[i],
                         1+(j>0?dp3[j-1]:0));
        }
        //cout << dp1[i] << " ";
    }
    // cout << endl;

    cout << dp1[n-1] << endl;
    cout << *max_element(dp2, dp2+n) << endl;
    cout << dp3[n-1] << endl;

    return 0;
}
