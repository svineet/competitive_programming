/*
 * Sort the array with merge sort and count
 * inversions too
 */
#include <iostream>
#include <algorithm>
using namespace std;


long long merge(long long src[], int left, int mid, int right) {
    // Merge srt[left..mid] and src[mid+1..right] and store
    // the result into src

    long long invs = 0;
    int res[right-left+1];
    int lptr = left;
    int rptr = mid+1;
    int dptr = 0;
    while (lptr <= mid && rptr <= right && dptr<right-left+1) {
        if (src[lptr] <= src[rptr]) {
            res[dptr++] = src[lptr++];
        } else if (src[lptr] > src[rptr]) {
            invs += (mid-lptr+1);
            res[dptr++] = src[rptr++];
        }
    }

    while (lptr <= mid)
        res[dptr++] = src[lptr++];

    while (rptr <= right)
        res[dptr++] = src[rptr++];

    for (int i=left, si=0; i<=right; i++, si++)
        src[i] = res[si];

    return invs;
}


/*
 * Parameters
 *   - left:  left index of interval
 *   - right: right index of interval
 *   - src[]: original array
 *
 * Side effects:
 *   - Sorts the src array
 *
 * Returns
 *   - number of inversions
 */
long long merge_sort(long long src[], int left, int right) {
    if (left >= right) return 0;

    long long invs = 0;
    int mid = (left+right)/2;
    invs += merge_sort(src, left, mid);
    invs += merge_sort(src, mid+1, right);
    invs += merge(src, left, mid, right);

    return invs;
}


bool custom_compare(const int left, const int right) {
    return left > right;
}


int main(int argc, char **argv) {
    int n; cin >> n;
    long long arr[n];
    for (int i=0; i<n; i++)
        cin >> arr[i];

    sort(arr, arr+n, custom_compare);
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

    long long invs = merge_sort(arr, 0, n-1);
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << invs << endl;

    return 0;
}

