#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);

    double PI = 4.0*atan2(1, 1);
    double angle[n];
    for (int i=0; i<n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        angle[i] = (atan2(y, x)*180.0)/PI;
    }
    sort (angle, angle+n);

    double mn = angle[n-1]-angle[0];
    for (int i=1; i<n; i++) {
        mn = min(mn, 360-(angle[i]-angle[i-1]));
    }
    printf("%lf\n", mn);

    return 0;
}
