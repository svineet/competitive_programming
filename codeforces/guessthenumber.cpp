#include <bits/stdc++.h>
using namespace std;

int main() {
    int left = 1, right = 1e6;
    while (left != right) {
        int mid = (left+right+1)/2;
        cout << mid << endl;
        string str; cin >> str;
        if (str == "<") {
            right = mid-1;
        } else {
            left = mid;
        }
    }
    assert (left == right);
    cout << "! " << left << endl;
}
