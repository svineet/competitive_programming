#include <bits/stdc++.h>
using namespace std;

int main() {
    long long l, r; cin >> l >> r;

    vector<long long> lucky;
    lucky.reserve(1000);
    // 2^9 - 2 lucky numbers are possible
    // under 1e9
    long long mult = 2;
    for (int digits=1; digits<=9; digits++) {
        for (int i=0; i<mult; i++) {
            long long cur = 0;
            long long tener = 1;
            for (int j=0; j<digits; j++) {
                if ((1<<j)&i)
                    cur += tener*7;
                else
                    cur += tener*4;
                tener *= 10;
            }
            lucky.push_back(cur);
        }
        mult *= 2;
    }
    sort (lucky.begin(), lucky.end());
    lucky.push_back(4444444444);
    // For 1E9

    long long sum = 0;
    int ldex = lower_bound(lucky.begin(), lucky.end(), l)-lucky.begin();
    int rdex = lower_bound(lucky.begin(), lucky.end(), r)-lucky.begin();
 
    long long last = l;
    for (int i=ldex; i<=rdex; i++) {
        sum += lucky[i]*(min(lucky[i], r)-last+1);
        last = lucky[i]+1;
    }
    cout << sum << endl;

    return 0;
}
