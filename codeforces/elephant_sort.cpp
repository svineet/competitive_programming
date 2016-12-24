#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    long long array[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }
    long long count = 0;
    long long maxtill = array[0], mintill = array[0];
    for (int i=1; i<n; i++) {
        if (array[i-1]>array[i])
            count += array[i-1]-array[i];
    }
    cout << count << endl;
    
    return 0;
}
