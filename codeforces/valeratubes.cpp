#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k; cin >> n >> m >> k;

    int approx = (n*m)/k;
    int curprox = approx;
    int leftovers = (n*m)%k;

    int cx = 1, cy = 1;
    int ay=1;
    while (k!=0) {
        curprox = approx;
        if (k==1) {
            curprox += leftovers;
            // Deal with leftover squares in the last iteration
        }

        cout << curprox;
        while (curprox--) {
            cout << " " << cx << " " << cy;
            cy+=ay;
            if (cy>m) {
                cy = m; cx++; ay=-ay;
            } else if (cy<1) {
                cy = 1; cx++; ay=-ay;
            }
            // Start going in the opposite direction
        }
        cout << endl;

        k--;
    }

    return 0;
}
