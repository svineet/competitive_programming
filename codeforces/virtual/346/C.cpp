#include <bits/stdc++.h>
using namespace std;

int choice[100000];
int array[100000];

int main() {
    int n, m; cin >> n >> m;
    int choiceptr = 0;
    for (int i=0; i<n; i++)
        scanf("%d", &array[i]);
    sort (array, array+n);

    long long cursum = 0;
    int aptr = 0;
    for (int i=1; i<=1e9; i++) {
        if (aptr<n && array[aptr] == i) {
            aptr++; continue;
        } else {
            if (cursum+i<=m) {
                choice[choiceptr] = i;
                cursum += i;
                choiceptr++;
            } else {
                break;
            }
        }
    }

    printf("%d\n", choiceptr);
    for (int i=0; i<choiceptr; i++)
        printf("%d ", choice[i]);
    printf("\n");

    return 0;
}
