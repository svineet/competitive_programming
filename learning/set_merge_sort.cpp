#include <stdio.h>

void Merge(int A[], int m, int B[], int n, int dest[]) {
    int pointerA=0, pointerB=0, pointerDest=0;
    while (pointerA!=m && pointerB!=n) {
        printf("%d %d %d\n", pointerA, pointerB, pointerDest);

        if(A[pointerA] == B[pointerB]) {
            dest[pointerDest] = A[pointerA];
            pointerA++; pointerB++; pointerDest++;
            continue;
        }

        if (A[pointerA] < B[pointerB]) {
            pointerA++;
            continue;
        }
        else {
            pointerB++;
            continue;
        }
    }
}

int main() {
    int destlel[8];
    int array1[5] = {1, 3, 4, 6, 8};
    int array2[3] = {3, 4, 5};
    Merge(array1, 5, array2, 3, destlel);

    for (int i=0; i<8; i++) printf("%d ", destlel[i]);
    printf("\n");
}
