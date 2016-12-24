#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int array[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }
    sort (array, array+n);

    for (int i=0; i<n-1; i++) {
        if (array[i+1] <= array[i]) {
            // Find an element that is strictly greater than
            // array[i] and replace array[i+1] with it
            int swapdex = -1;
            for (int j=i+2; j<n; j++) {
                if (array[j]>array[i] && (swapdex == -1 || array[j]<array[swapdex]))
                    swapdex = j;
            }
            if (swapdex == -1) {
                sort (array+i+1, array+n);
                continue;
            }
            swap(array[i+1], array[swapdex]);
        }
    }

    int count = 0;
    for (int i=0; i<n-1; i++) {
        if (array[i+1]>array[i]) count++;
        //cout << array[i] << endl;
    }
    cout << count << endl;

    return 0;
}
