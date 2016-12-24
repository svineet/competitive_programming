#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    n += 2;
    int coords_x[n];
    coords_x[0] = 0;
    coords_x[1] = 100000;

    for (int i=2; i<n; i++) {
        int temp;
        scanf("%d %d", &coords_x[i], &temp);
    }

    std::sort(coords_x, coords_x+n);

    int maxdiffindex=-1, carry=-1000;
    for (int i=0; i<n-1; i++) {
        if (coords_x[i+1]-coords_x[i]>carry) {
            carry = coords_x[i+1]-coords_x[i];
            maxdiffindex = i;
        }
    }

    printf("%d\n", carry*500);
    return 0;
}

