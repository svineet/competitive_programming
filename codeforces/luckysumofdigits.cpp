#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n; cin >> n;
    int dp[n+1];
    int parent[n+1];
    dp[0] = 0;
    parent[0] = -1;

    for (int i=1; i<=n; i++) {
        dp[i] = parent[i] = -1;

        int cand4=-1,
            cand7=-1;
        if (i-4>=0 && dp[i-4] != -1) {
            cand4 = 1+dp[i-4];
            parent[i] = 4;
        }

        if (i-7>=0 && dp[i-7] != -1) {
            cand7 = 1+dp[i-7];
            parent[i] = 7;
        }

        if (cand4 == -1 && cand7 == -1) {
            continue;
        } else if (cand4==-1 && cand7!=-1) {
            dp[i] = cand7;
            parent[i] = 7;
        } else if (cand7==-1 && cand4!=-1) {
            dp[i] = cand4;
            parent[i] = 4;
        } else if (cand4 <= cand7) {
            dp[i] = cand4;
            parent[i] = 4;
        } else {
            dp[i] = cand7;
            parent[i] = 7;
        }
    }

    if (dp[n] == -1) {
        cout << -1 << endl;
        return 0;
    }

    string result = "";
    int curindex = n;
    while (curindex != 0) {
        result += (parent[curindex]==4?"4":"7");
        curindex -= parent[curindex];
    }
    cout << result << endl;

    return 0;
}
