#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

double a[1000010];

int main() {
    int n; scanf("%d", &n);
    int len = 1; a[1] = 0; double sum = 0;
    while (n--) {
        int c; scanf("%d", &c);
        if (c==1) {
            int d, x; scanf("%d%d", &d, &x);
            a[d] += x;
            sum += d*x;
        } else if (c==2) {
            int x; scanf("%d", &x); len++;
            a[len-1] -= x;
            a[len] = x;
            sum += x;
        } else if (c==3) {
            a[len-1] += a[len];
            sum -= a[len];
            a[len] = 0;
            len--;
        }
        printf("%.10f\n", sum/(double)len);
    }

    return 0;
}
