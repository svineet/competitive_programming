#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int cas=0; cas<t; cas++) {
        int n; cin >> n;
        int array[n];
        int pos_sums = 0;
        for (int i=0; i<n; i++) {
            cin >> array[i];
            if (array[i]>0) pos_sums+=array[i];
        }

        int max_sum = *max_element(array, array+n);
        if (pos_sums == 0) pos_sums = max_sum;
        int max_overall = array[0],
            max_current = array[0];
        /*
         * Kadane's algorithm.
         * A greedy/DP (disputed) algorithm to compute
         * maximum subarray sum.
         */
        for (int i=1; i<n; i++) {
            max_current = max(array[i], max_current+array[i]);
            // ^ Start a new subarray to consider from i
            // or add a[i] to the subarray we have been considering
            // currently. Whichever is better.
            if (max_current > max_overall)
                max_overall = max_current;
            // Just record the best subarray we got.
        }
        cout << max_overall << " " << pos_sums << endl;
    }

    return 0;
}
