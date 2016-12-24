#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long array[3];
    cin >> array[0] >> array[1] >> array[2];

    long long count = 0;
    while (true) {
        sort(array, array+3);

        int c = (array[0]==0) + (array[1]==0) + (array[2]==0);
        if (c>=2) break;

        if (array[0]+array[1]+array[2]<3) break;
        if (array[0] == array[1] && array[1] == array[2]) {
            array[0]--; array[1]--; array[2]--;
            count++;
        } else if (array[2]>=2 && array[1]>=1) {
            array[1]--; array[2]-=2;
            count++;
        } else {
            break;
        }
    }
    cout << count << endl;

    return 0;
}
