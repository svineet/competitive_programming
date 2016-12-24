#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    pair<int, int> array[n];
    for (int i=0; i<n; i++) {
        cin >> array[i].first;
        cin >> array[i].second;
    }
    sort(array, array+n);
    int count = 0;
    for (int i=0; i<n; i++) {
        if (count <= array[i].second) {
            count = array[i].second;
        } else {
            count = array[i].first;
        }
    }
    cout << count << endl;
}
