#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    long long array[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }

    long long cost = abs(array[0]);
    for (int i=1; i<n; i++) {
        cost += abs(array[i]-array[i-1]);
    }
    cout << cost << endl;

    return 0;
}
