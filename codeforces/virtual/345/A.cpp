#include <bits/stdc++.h>
using namespace std;

int memo[1000][1000];

int solve(int a, int b) {
    if (a<=0 || b<=0) return 0;
    if (a<=1 && b<=1) return 0;

    if (memo[a][b] != -1)
        return memo[a][b];

    memo[a][b] = 1+max(solve(a-2, b+1), solve(a+1, b-2));
    return memo[a][b];
}

int main() {
    int a, b; cin >> a >> b;
    for (int i=0; i<1000; i++) {
        for (int j=0; j<1000; j++) {
            memo[i][j] = -1;
        }
    }
    cout << solve(a, b) << endl;

    return 0;
}
