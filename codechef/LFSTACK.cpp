#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int t; cin >> t;
    for (int cs=0; cs<t; cs++) {
        int n; cin >> n;
        vector< vector<int> > insertions;
        int pointers[n]; int totlen=0;
        for (int i=0; i<n; i++) {
            int elems; cin >> elems;
            totlen+=elems;
            vector<int> temp(elems);
            for (int j=0; j<elems; j++) {
                int input_xd; cin >> input_xd;
                temp.push_back(input_xd);
            }
            insertions.push_back(temp);
            pointers[i] = 0;
        }
        int sequence[totlen];
        for (int i=0; i<totlen; i++) {
            cin >> sequence[i];
        }
    }

    return 0;
}
