#include <bits/stdc++.h>
using namespace std;


int main(int argc, char **argv) {
    int n, k; cin >> n >> k;
    long long arr[n];
    for (int i=0; i<n; i++)
        cin >> arr[i];

    long long ans = 0;
    long long diff[n-1]; // diff[i] = arr[i+1]-arr[i]. diff is of length n-1.
    for (int i=1; i<n; i++)
        diff[i-1] = arr[i-1] - arr[i];

    sort(diff, diff+n-1);
    // Taking a diff means taking a separator
    // If there are k partitions, then there must be k-1 separators
    ans = arr[n-1]-arr[0];
    for (int i=0; i<k-1; i++)
        ans += diff[i];

    cout << ans << endl;

    return 0;
}

