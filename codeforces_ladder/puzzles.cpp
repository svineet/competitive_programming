#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int array[m];
    for (int i=0; i<m; i++) {
        cin >> array[i];
    }
    sort (array, array+m);
    int result = 100000000;
    for (int i=0; i<(m-n+1); i++) {
        result = min(result,
                     array[i+n-1]-array[i]);
    }
    cout << result << endl;

    return 0;
}
