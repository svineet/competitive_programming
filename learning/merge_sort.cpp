#include <stdio.h>

void Merge(int A[], int m, int B[], int n, int destination[]) {
    // Merge A[0..m-1] and B[0..n-1] to destination[0..m+n-1]
    int pointerInDest = 0;
    int pointerInA = 0, pointerInB = 0;
    while (pointerInDest < m+n) {
        if (pointerInA == m || A[pointerInA] > B[pointerInB]) {
            // Insert B element into destination and increment pointer
            destination[pointerInDest] = B[pointerInB];
            pointerInDest++; pointerInB++;
        }
        
        if (pointerInB == n || B[pointerInB] >= A[pointerInA]) {
            destination[pointerInDest] = A[pointerInA];
            pointerInDest++; pointerInA++;
        }
    }
}

void MergeSort(int origin[], int left, int right, int destination[]) {
    if (right-left==1) {
        // We have only one element, let's copy it over.
        destination[0] = origin[left];
        return;
    }

    int mid = (left+right)/2;
    int leftMerger[mid-left];
    int rightMerger[right-mid];

    MergeSort(origin, left, mid, leftMerger);
    MergeSort(origin, mid, right, rightMerger);
    Merge(leftMerger, mid-left, rightMerger, right-mid, destination);
}

int main() {
    int array1[5] = {5, 4, 3, 2, 1};
    int array2[5];
    MergeSort(array1, 0, 5, array2); 

    for (int i=0; i<5; i++) printf("%d ", array2[i]);
    printf("\n");
}
