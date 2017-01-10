#include <bits/stdc++.h>
using namespace std;

struct triplet {
    pair<int, int> span;
    int index;
};

bool comparer(const triplet a, const triplet b) {
    return a.span<b.span;
}

int main() {
    int n; cin >> n;
    triplet array[n];
    for (int i=0; i<n; i++) {
        cin >> array[i].span.first >> array[i].span.second;
        array[i].index = i+1;
    }
    sort (array, array+n, comparer);

    int dp[n], parent[n];
    dp[0] = 1; parent[0] = -1;
    int maxdex = 0;
    for (int i=1; i<n; i++) {
        dp[i] = 1; parent[i] = -1;
        for (int j=0; j<i; j++) {
            if (array[j].span.first<array[i].span.first &&
                array[j].span.second>array[i].span.second) {
                if (dp[j]+1>dp[i]) {
                    dp[i] = dp[j]+1; parent[i] = j;
                }
            }
        }
        if (dp[maxdex]<dp[i]) maxdex = i;
    }

    cout << dp[maxdex] << endl;
    int cur = maxdex;
    while (cur != -1) {
        cout << array[cur].index << " ";
        cur = parent[cur];
    }
    cout << endl;

    return 0;
}
