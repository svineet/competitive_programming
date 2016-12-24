#include <bits/stdc++.h>
using namespace std;

string str; 
int n;
bool palindrome[4001][4001];

int main() {
    cin >> str; n = str.length();
    
    for (int i=0; i<n; i++) {
        palindrome[i][i] = true;
    }

    for (int subsize=2; subsize<=n; subsize++) {
        for (int i=0; i<=(n-subsize); i++) {
            int j = i+subsize-1;
            if (str[i] == str[j])
                palindrome[i][j] = (subsize!=2?palindrome[i+1][j-1]:true);
            else
                palindrome[i][j] = false;
        }
    }

    int dp[n];
    int parent[n];
    dp[0] = 1;
    parent[0] = -1;
    for (int i=1; i<n; i++) {
        dp[i] = 1+dp[i-1];
        parent[i] = i-1;
        // Trivial palindrome
        for (int j=i-1; j>=0; j--) {
            if (palindrome[j][i]) {
                if ((j>0?dp[j-1]:0)+1<dp[i]) {
                    dp[i] = (j>0?dp[j-1]:0)+1;
                    parent[i] = j-1;
                }
            }
        }
    }

    cout << dp[n-1] << endl;
    stack<int> result;
    int cur = n-1;
    while (cur != -1) {
        result.push(cur);
        cur = parent[cur];
    }

    int last = 0;
    while (!result.empty()) {
        for (int j=last; j<=result.top(); j++)
            cout << str[j];
        cout << " ";
        last = result.top() + 1;
        result.pop();
    }
    cout << endl;

    return 0;
}
