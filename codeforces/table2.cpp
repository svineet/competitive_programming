#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long array[3];
    cin >> array[0] >> array[1] >> array[2];
    sort (array, array+3);
    long long best = (array[0]+array[1]+array[2])/3;

    if (2*(array[0]+array[1]) <= array[2])
        cout << array[0]+array[1] << endl;
    else
        cout << best << endl;
    
    return 0;
}
