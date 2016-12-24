#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    int array[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }

    vector< pair<int, int> > combs;
    // Pair of combination length, bitwise representation
    combs.reserve(1<<n);
    for (int i=0; i<(1<<n); i++) {
        // Assume i is the bit wise representation
        // of a combination
        int k = 0;
        for (int j=0; j<32; j++) {
            // 32 bits to check for in an int variable
            if ((1<<j)&i) {
                k++;
            }
        }
        combs.push_back(make_pair(k, i));
    }
    sort (combs.begin(), combs.end());

    for (vector< pair<int, int> >::iterator i=combs.begin();
         i!=combs.end();
         i++) {
        for (int j=0; j<32; j++) {
            if ((1<<j)&(*i).second) {
                cout << array[j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
