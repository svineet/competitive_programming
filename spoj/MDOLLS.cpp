#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int cs=0; cs<t; cs++) {
        int m;
        scanf("%d", &m);
        pair<int, int> data[m]; // [(height, weight)...]
        for (int i=0; i<m; i++) {
            scanf("%d", &data[i].first);
            scanf("%d", &data[i].second);
            // printf("%d %d ", data[i].first, data[i].second);
        }
        // printf("\n");

        sort(data, data+m);

        int dp[m];
        dp[0] = 1;
        for (int i=1; i<m; i++) {
            int max_dp = 0;
            for (int j=0; j<i; j++) {
                if (data[j].first<data[i].first &&
                        data[j].second<data[i].second) {
                    // j can be put into i
                    max_dp = max(max_dp, dp[j]);
                    // So we take the j-th doll as a
                    // predecessor to the i-th doll
                }
            }
            dp[i] = max_dp + 1;
            // We added this element to max dp we found;
        }

        printf("%d\n", m+1-*max_element(dp, dp+m));
    }

    return 0;
}
