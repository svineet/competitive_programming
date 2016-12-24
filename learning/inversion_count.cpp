#include <iostream>
#include <algorithm>
using namespace std;

int MergeCount(int left[],  int m,
                     int right[], int n,
                     int destination[]) {
    int lptr=0,
        rptr=0,
        dptr=0;
    int inversions=0;
    cout << m << ";" << n << endl;
    while (dptr<m+n) {
        if (lptr == m || left[lptr] > right[rptr]) {
            inversions += m-lptr;
            cout << lptr << " " << rptr << endl;
            destination[dptr] = right[rptr];
            rptr++; dptr++;
        } else if (rptr == n || left[lptr] <= right[rptr]) {
            destination[dptr] = left[lptr];
            lptr++; dptr++;
        }
    }
    return inversions;
}

int MergeSortCount(int A[], int start, int end,
                         int B[]) {
    if (end == start) {
        // Only one element
        B[0] = A[start];
        return 0;
    }

    int mid = (start+end)/2;
    int sizel = mid-start+1,
        sizer = end-mid;
    /*cout << sizel << " " << sizer << endl;
    cout << start << " " << end << endl;*/
    int left[sizel], right[sizer];

    int countL = MergeSortCount(A, start, mid, left);
    int countR = MergeSortCount(A, mid+1, end, right);
    int countM = MergeCount(left, sizel,
                             right, sizer,
                             B);
    return countM+countL+countR;
}

int  main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int array[n];
        for (int i=0; i<n; i++) {
            cin >> array[i];
        }
        int dest[n];
        int count = 0;
        count = MergeSortCount(array, 0, n-1, dest);
        cout << count << endl;
    }

    return 0;
}
