#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int height[n+1];
    height[0] = 0;
    for (int i=1; i<=n; i++)
        cin >> height[i];

    long long cost = 0;
    int energy = 0;
    for (int i=0; i<n; i++) {
        energy += height[i]-height[i+1];
        if (energy < 0) {
            cost += abs(energy);
            energy = 0;
        }
    }
    cout << cost << endl;

    return 0;
}
