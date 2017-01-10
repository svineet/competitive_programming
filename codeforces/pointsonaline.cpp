#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int array[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }

    long long count = 0;
    for (int i=0; i<n; i++) {
        int index = upper_bound(array+i, array+n, array[i]+k)-array-1;
        //cout << i << " " << index << endl;
        long long choosers = index-(i+2)+1;
        if (index-i+1>2) {
            count += choosers*(choosers+1)/2;
        }
        // Select one of the elements between
        // and i and index and endpoints
    }
    cout << count << endl;
}
