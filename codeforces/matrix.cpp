#include <bits/stdc++.h>
using namespace std;

long long cache[9*4000 + 100];

int main() {
    long long a; cin >> a;
    string str; cin >> str;
    int n = str.length();
    long long partials[n];
    for (int i=0; i<n; i++) {
        partials[i] = (i>0?partials[i-1]:0)+(str[i]-'0');
    }

    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            long long sum = partials[j]-(i>0?partials[i-1]:0);
            cache[sum]++;
        }
    }

    // cache[x] denotes how many
    // subarrays obtain a sum of
    // x.

    long long count = 0;
    if (a==0) {
        // if a == 0
        // then we have to count
        // subarrays such that sum(x1, x2)*sum(y1, y2) == 0

        count += 2*cache[0]*n*(n+1)/2;
        // Number of ways when we choose one subarray
        // that is zero, but the other can be anything.
        count -= cache[0]*cache[0];
        // We double counted the ways in which
        // we get two zeroes.
        cout << count << endl;

        return 0;
    }

    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            int sum = partials[j]-(i>0?partials[i-1]:0);
            if (sum == 0) continue;

            if (a%sum==0) {
                if (a/sum > 9*n) continue;
                // There can be no sums that are above
                // 9*n, which is the case where
                // all numbers are 9.
                count += cache[a/sum];
            }
        }
    }

    cout << count << endl;

    return 0;
}
