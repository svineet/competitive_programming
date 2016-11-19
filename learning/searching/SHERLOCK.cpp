#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int cas=0; cas<t; cas++) {
        int n;
        scanf("%d", &n);
        int array[n];
        int partialSums[n];
        for (int i=0; i<n; i++) {
            scanf("%d", &array[i]);
            if (i==0) {
                partialSums[i] = array[i];
            }
            else {
                partialSums[i] = array[i] + partialSums[i-1];
            }
        }

        bool gotem = false;
        for (int i=0; i<n; i++) {
            int lsum=0, rsum=0;
            if (i!=0) {
                lsum = partialSums[i-1];
            }
            if (i!=n-1) {
                rsum = partialSums[n-1]-partialSums[i];
            }
            if (lsum==rsum) {
                gotem = true;
                break;
            }
        }
        if (gotem) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}
