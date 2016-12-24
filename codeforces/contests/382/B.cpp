#include <bits/stdc++.h>
using namespace std;

bool compre(int a, int b) {
    return a>b;
}

int main() {
    int n; scanf("%d", &n);
    int n1, n2; scanf("%d%d", &n1, &n2);
    int array[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }
    sort (array, array+n, compre);

    int sp = min(n1, n2), bp = max(n1, n2);

    double am1 = 0, am2 = 0;
    for (int i=0; i<sp; i++) {
        am1+=array[i];
    }
    am1 = am1/sp;

    for (int i=sp; i<sp+bp; i++) {
        am2 += array[i];
    }
    am2 = am2/bp;

    printf("%.8f\n", am1+am2);

    return 0;
}
