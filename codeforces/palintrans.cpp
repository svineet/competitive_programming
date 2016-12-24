#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n, p; cin >> n >> p;
    int center = (n/2)-1 ;
    // Center is actually the last element in the left part
    // We don't care since cost array is symmetric around center (real)
    // 1. What if p > rightmost?
    // 2. What if p < leftmost?
    // 3. What if p == center?

    if (p>(n/2)) {
        if (n%2==0) {
            p = n-p;
        } else {
            p = n-p;
        }
    } else {
        p--;
    }

    string inp; cin >> inp;

    int cost[n];
    int partials[n];
    int rightmost=-1, leftmost=-1;
    for (int i=0; i<n/2; i++) {
        cost[i] = 0;
        if (inp[i] != inp[n-i-1]) {
            int c = abs(inp[i]-inp[n-i-1]);
            c = min(26-c, c);
            cost[i] = cost[n-i-1] = c;
            if (leftmost == -1)
                leftmost = i;

            rightmost = i;
        }
        partials[i] = (i>0?partials[i-1]:0)+cost[i];
    }
    if (n%2!=0) cost[n/2] = 0;


    if (rightmost == -1 && leftmost == -1) {
        cout << 0 << endl;
        return 0;
    }

    int finalcost = cost[p];
    finalcost += partials[rightmost]-partials[leftmost]+cost[leftmost];
    // We always fix the current character
    // and we always have to fix all deformities
    if (leftmost<=p && p<=rightmost) {
        int rdist = rightmost-p;
        int ldist = p-leftmost;
        finalcost += min(2*rdist+ldist,
                         2*ldist+rdist);
        finalcost -= cost[p];
        // We counted p cost twice
    } else  if (p<leftmost) {
        finalcost += rightmost-p;
    } else if (p>rightmost) {
        finalcost += p-leftmost;
    }

    cout << finalcost << endl;

    return 0;
}
