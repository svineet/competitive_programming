#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int array[n];
    int dp[n];
    int parent[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
        dp[i] = 0;
        parent[i] = -1;
    }

    dp[0] = 1; parent[0] = -1;
    // Longest increasing subsequence ending at 0
    // is the first element itself, a subsequence of only
    // one element. Making the maximum subsequence length
    // 1.
    for (int i=1; i<n; i++) {
        // dp[i] = 1 + max(dp[j] in j=0..i-1 such that a[j]<a[i])
        // Take maximum subsequence length that we previously
        // found for a node that connects to i-th node
        int maxdex = -1;
        int maxval = 0;
        for (int j=0; j<i; j++) {
            if (dp[j]>maxval && array[j]<array[i]) {
                // We found a node that enters i-th node
                // with a nice maximum length;
                maxdex = j;
                maxval = dp[j];
            }
        }
        dp[i] = 1 + maxval;
        parent[i] = maxdex;
    }

    int maxdpindex = 0;
    for (int i=0; i<n; i++) {
        if (dp[i]>dp[maxdpindex]) {
            maxdpindex = i;
        }
    }

    int curind = maxdpindex;
    while (parent[curind]!=-1) {
        cout << array[curind] << "->";
        curind = parent[curind];
    }
    cout << array[curind] << endl;

    return 0;
}
