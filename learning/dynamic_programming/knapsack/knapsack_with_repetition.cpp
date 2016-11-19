#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int weights[n], values[n];
    int capacity=0;
    cin >> capacity;
    for (int i=0; i<n; i++)
        cin >> weights[i];
    for (int i=0; i<n; i++)
        cin >> values[i];

    int knap[max_weight+1];
    knap[0] = 0; // Zero value of an empty array
    for (int i=1; i<max_weight+1; i++) {
        // Maximize K(capacity-weights[j])+values[j]
        // Basically trying to identify which node is the best origin
        // of this current subproblem.
        int max_val=-10;
        for (int j=0; j<n; j++) {
            if (knap[i-weights[j]]+values[j] > max_val) {
                max_val = knap[i-weight[j]]+values[j];
                // knap[<weight we're trying to find an answer for
                // right now> - weight of
            }
        }
    }

    return 0;
}
