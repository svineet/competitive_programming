#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    int n; cin >> n;
    int k; cin >> k;

    int array[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }
    sort (array, array+n);
    int lptr=0,rptr=0;
    long long pairs=0;
    while (rptr<n && lptr<n) {
        if (lptr == rptr) {
            rptr++; continue;
        }

        if (array[rptr]-array[lptr]>=k) {
            pairs += n-rptr;
            lptr++; continue;
        } else {
            rptr++;
        }
    }
    cout << pairs << endl;

    return 0;
}
