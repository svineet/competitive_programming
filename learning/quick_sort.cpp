#include <iostream>
using namespace std;

int partition(int A[], int left, int right) {
    // Partition A into three parts
    // with A[left] as pivot
    
    int piv = A[left];
    int i = left+1;
    for (int j=left+1; j<=right; j++) {
        if (A[j] < piv) {
            swap(A[i], A[j]);
            i++;
        }
    }

    swap(A[left], A[i-1]);
    return i-1;
}

void quick_sort(int A[], int left, int right) {
    if (left >= right)
        return;

    int pivot_position = partition(A, left, right);
    quick_sort(A, left, pivot_position);
    quick_sort(A, pivot_position+1, right);
}

int main(int argc, char **argv) {
    int n; cin >> n;
    int arr[n];
    for (int i=0; i<n; i++)
        cin >> arr[i];

    quick_sort(arr, 0, n-1);

    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

