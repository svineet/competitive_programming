#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    string inp; cin >> inp;
    int n = inp.length();

    vector<char> output;
    output.reserve(n);
    output.push_back(inp[0]);
    int optr = 0;
    for (int i=1; i<n; i++) {
        char candidate = inp[i];
        bool take = true;

        if (optr>=2) {
            // Two same, then another 2 same
            if (candidate == output[optr] &&
                output[optr-1] == output[optr-2]) {
                take = false;
            }
        }

        if (optr>=1) {
            // Three consecutive similar characters
            if (candidate == output[optr] &&
                candidate == output[optr-1]) {
                take = false;
            }
        }

        if (take) {
            output.push_back(candidate);
            optr++;
        }
    }

    for (int i=0; i<=optr; i++) {
        cout << output[i];
    }
    cout << endl;

    return 0;
}
