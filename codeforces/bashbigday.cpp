#include <bits/stdc++.h>
using namespace std;

bool sieve[100001];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    fill (sieve, sieve+100001, true);
    sieve[1] = false;
    for (int i=4; i<100001; i+=2)
        sieve[i] = false;
    for (long long i=3; i<100001; i+=2) {
        if (sieve[i])
            for (long long j=i*i; j<100001; j+=i) sieve[j] = false;
    }

    int facs[100001];
    fill (facs, facs+100001, 0);
    for (int i=0; i<n; i++) {
        if (sieve[arr[i]]) {
            facs[arr[i]]++;
            // cout << arr[i] << " " << arr[i] << endl;
            continue;
        }

        for (int j=2; j<=sqrt(arr[i]); j++) {
            if (arr[i]%j==0 && sieve[j]) {
                facs[j]++;
                // cout << arr[i] << " " << j << endl;
            }

            if (arr[i]%j == 0) {
                int comp = arr[i]/j;
                if (sieve[comp] && comp != j) {
                    facs[comp]++;
                    // cout << arr[i] << " " <<  comp << endl;
                }
            }
        }
    }

    int mx = 1;
    for (int i=2; i<100001; i++)
        if (facs[i]>mx) mx = facs[i];
    cout << mx << endl;

    return 0;
}
