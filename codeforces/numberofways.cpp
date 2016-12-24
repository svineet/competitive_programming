#include <iostream>
#include <algorithm>
using namespace std;

long long array[500005];
long long partials[500005];

long long get_sum (long long partials[],
                   int i, int j) {
    return partials[j]-partials[i]+array[i];
}

int main() {
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        cin >> array[i];
        if (i>0)
            partials[i] = partials[i-1] + array[i];
        else
            partials[i] = array[i];
    }

    long long ways = 0;
    long long want = 0;
    if (partials[n-1]%3==0) {
        want = partials[n-1]/3;
    } else {
        cout << 0 << endl;
        return 0;
    }

    long long count[n];
    long long sums[n];
    for (int i=n-1; i>=0; i--) {
        if (get_sum(partials, i, n-1) == want)
            count[i] = 1;
        else
            count[i] = 0;
        sums[i] = (i+1!=n?sums[i+1]:0) + count[i];
    }
    /*for (int i=0; i<n; i++) {
        cout << count[i] << " ";
    }
    cout << endl;
    for (int i=0; i<n; i++) {
        cout << sums[i] << " ";
    }
    cout << endl;*/

    for (int i=1; i<n-1; i++) {
        long long left = get_sum(partials, 0, i-1);
        if (left == want) {
            ways += sums[i+1];
        }
    }
    cout << ways << endl;
    
    return 0;
}
