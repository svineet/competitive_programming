#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const long long MODDER = 1e9 + 7;

int main() {
    int n, m; cin >> n >> m;
    string inputs[n];

    for (int i=0; i<n; i++) {
        cin >> inputs[i];
    }

    long long result = 1;
    for (int i=0; i<m; i++) {
        int cache[30] = {0};
        int count = 0;
        for (int j=0; j<n; j++) {
            if (cache[inputs[j][i]-'A'] == 0) {
                cache[inputs[j][i]-'A']++;
                count++;
            }
        }
        result *= count;
        result %= MODDER;
    }
    cout << result << endl;
    
    return 0;
}
