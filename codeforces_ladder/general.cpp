#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int array[n];
    int mindex=0,
        maxdex=0;
    for (int i=0; i<n; i++) {
        cin >> array[i];
        if (array[i]<=array[mindex])
            mindex = i;
        if (array[i]>array[maxdex])
            maxdex = i;
    }
    int steps = 0;
    steps = maxdex+(n-mindex-1);
    if (maxdex>mindex) {
        steps-=1;
    }
    cout << steps << endl;

    return 0;
}
