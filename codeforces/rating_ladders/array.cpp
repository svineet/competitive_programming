#include <bits/stdc++.h>
using namespace std;

int seen[200000];

int main() {
    int n, k; cin >> n >> k;
    int arr[n];
    for (int i=0; i<n; i++)
        cin >> arr[i];

    int lptr = 0,
        rptr = 0;
    int uniqs = 1;
    seen[arr[0]]++;
    int a = -2,
        b = -2;
    while (rptr < n) {
        if (lptr > rptr) {
            rptr++;
            if (rptr >= n) break;
            seen[arr[rptr]]++;
            if (seen[arr[rptr]] == 1)
                uniqs++;
            continue;
        }

        if (uniqs == k) {
            a = lptr;
            b = rptr;
        }

        if (uniqs == k) {
            // We have our goal.
            // Let's try to compress.
            seen[arr[lptr]]--;
            if (seen[arr[lptr]] == 0)
                uniqs--;
            lptr++;
        } else {
            // More unique numbers needed.
            rptr++;
            if (rptr >= n) break;
            seen[arr[rptr]]++;
            if (seen[arr[rptr]] == 1)
                uniqs++;
        }
    }

    cout << a+1 << " " << b+1 << endl;

    return 0;
}
