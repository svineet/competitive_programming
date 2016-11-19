#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int hotels[n];
    for (int i=0; i<n; i++) {
        cin >> hotels[i];
    }
    int lptr=0,
        rptr=0;
    int cur_sum=0;
    int max_sum=0;
    for (int i=0; i<n; i++) {
        if (cur_sum+hotels[i]<=m) {
            // We can accomodate this element ez
            // So we extend our window
            rptr++; cur_sum+=hotels[i];
            if (cur_sum>max_sum) max_sum = cur_sum;
        }
        else if(cur_sum+hotels[i]>m) {
            // Try to include hotels[i] instead of hotels[lptr]
            cur_sum -= hotels[lptr];
            lptr++; i--;
            // Repeat evaluation of this hotels[i] by decrementing i
            // If hotels[i] becomes includable next iteration the first
            // clause of the if is executed.
            // Else we again shrink the window rightwards.
        }
    }

    cout << max_sum << endl;

    return 0;
}
