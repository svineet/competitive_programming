#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d; cin >> n >> d;
    int array[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }

    long long count = 0;
    for (int i=1; i<n; i++) {
        if (array[i]<=array[i-1]) {
            int lcount = ceil((array[i-1]+1-array[i])/double(d));
            count += lcount;
            array[i] += lcount*d;
        }
    }
    cout << count << endl;

    return 0;
}
