#include <iostream>
using namespace std;

int partition(int A[], int left, int right) {
    // Partition A into three parts
    // with A[left] as pivot

    int i = left-1;
    for (int j=left; j<right; j++) {
        // A[i+1..j] is > A[right]

        if (A[j] <= A[right]) {
            // A[j] <= pivot, we increment i and swap
            // Belongs in left..i area
            i++;
            swap(A[i], A[j]);

            // After swap, element A[i] (abhi wala i)
            // to jth pos, so that j is extended too
            // thus j always increases
        } else {
            // A[j] > pivot, we just extend j anyway
            // Belongs in i+1..j area
            // do nothing
        }
    }

    swap(A[i+1], A[right]);
    return i;
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

