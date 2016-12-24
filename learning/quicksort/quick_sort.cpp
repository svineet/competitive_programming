#include <stdio.h>
#include <algorithm>

void Quicksort(int A[], int left, int right) {
    if (right-left<=1) {
        // Nothing to do as there is only 1 or no element in given segment
        return;
    }

    int yellow=left+1;
    for (int i=left+1; i<right; i++) {
        if (A[i] <= A[left]) {
            // This guy should be in lower
            std::swap(A[yellow], A[i]);
            yellow++;
            // Swap head with yellow and expand lower partition. Higher partition auto
            // expands as i++ happens automatically.
        }
    }
    std::swap(A[left], A[yellow-1]);
    // Partitioning is complete!
    printf("%d %d %d\n", left, right, yellow);
    for (int i=0; i<4; i++) printf("%d ", A[i]);
    printf("\n-----------------------------------\n");
    
    Quicksort(A, left, yellow);
    Quicksort(A, yellow+1, right);
}


int main() {
    int array[4] = {4, 3, 2, 1};
    Quicksort(array, 0, 4);

    for (int i=0; i<sizeof(array)/sizeof(int); i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
