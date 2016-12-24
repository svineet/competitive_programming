#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    long long n, k; cin >> n >> k;
    long long array[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }

    sort (array, array+n);

    long long partials[n];
    partials[0] = array[0];
    for (int i=1; i<n; i++) {
        partials[i] = partials[i-1]+array[i];
    }

    int best = 1, best_num = array[0];
    for (int i=1; i<n; i++) {
        int left = 0,
            right = i-1;
        int curbest = 0;
        //cout << "--------------" << endl;
        while (left<=right) {
            int mid = (left+right)/2;
            long long cost = (i-mid+1)*array[i]-(partials[i]-(mid>0?partials[mid-1]:0));
            //cout << mid << " " << cost << endl;
            if (cost>k) {
                left = mid+1;
                // Go right
            } else if (cost <= k) {
                curbest = max(curbest, i-mid+1);
                // i-mid+1 because A[i] comes for free
                // Go left
                right = mid-1;
            }
        }
        if (curbest>best) {
            best = curbest;
            best_num = array[i];
        }
    }
    cout << best << " " << best_num << endl;

    return 0;
}
