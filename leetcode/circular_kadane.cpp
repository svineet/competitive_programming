#include <bits/stdc++.h>
using namespace std;

int kadane(int arr[], int n) {
    int cur_max = 0, best_max = 0;
    for (int i=0; i<n; i++) {
        cur_max = max(0, cur_max+arr[i]);
        best_max = max(best_max, cur_max);
    }

    return best_max;
}

int main(int argc, char **argv) {
    int n; cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) cin >> arr[i];

    int proper_max = kadane(arr, n);
    int tot = 0;
    for (int i=0; i<n; i++) {
        tot += arr[i]; arr[i] = -arr[i];
    }
    int circular_max = tot+kadane(arr, n);

    cout << circular_max << endl;
    cout << max(circular_max, proper_max) << endl;

    return 0;
}

