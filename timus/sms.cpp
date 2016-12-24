#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    cin.ignore(10, '\n');

    string str;
    getline(cin, str);

    int len = str.length();
    int dp[len+1];
    // dp[i] is the minimum number of required
    // message for first i characters.
    int last_special = 0;
    dp[0] = 0;
    // No characters;
    for (int i=1; i<=len; i++) {
        char c = str[i-1];
        if (('A' <= c && c <= 'Z') ||
            ('a' <= c && c <= 'z') ||
            (c == ' ')) {
            dp[i] = 1+dp[max(i-m, last_special)];
            dp[i] = min(dp[i], 1+dp[max(0, i-n)]);
            // Use 1 n-lengthed any character message
            // or use the special message with only
            // latin characters.
        } else {
            // Special character.
            last_special = i;
            dp[i] = 1+dp[max(0, i-n)];
        }
    }

    cout << dp[len] << endl;

    return 0;
}
