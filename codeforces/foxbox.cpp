#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    int array[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }
    sort (array, array+n);

    int piles = 0;
    bool took = false;
    do {
        int sum = 0;
        took = false;
        for (int i=0; i<n; i++) {
            if (array[i] == -1)
                continue;

            if (array[i]>=sum) {
                array[i] = -1;
                took = true;
                sum++;
            }
        }
        if (took) piles++;
    } while (took);
    cout << piles << endl;

    return 0;
}
