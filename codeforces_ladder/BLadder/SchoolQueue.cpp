#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n, t; cin >> n >> t;
    string seq; cin >> seq;
    for (int cs=0; cs<t; cs++) {
        for (int i=0; i<n-1; i++) {
            if (seq[i] == 'B' && seq[i+1] == 'G') {
                seq[i] = 'G'; seq[i+1] = 'B';
                i++;
            }
        }
    }
    cout << seq << endl;

    return 0;
}
