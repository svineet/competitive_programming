#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int array[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }
    sort(array, array+n);
    long long count = 0;
    for (int i=0; i<n-1; i++) {
        int look = k-array[i]-1;
        int index = upper_bound(array+i+1, array+n, look)-array;
        count += index-i-1;
    }
    cout << count << endl;

    return 0;
}
