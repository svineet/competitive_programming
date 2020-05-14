#include <bits/stdc++.h>
using namespace std;


int main(int argc, char **argv) {
    int t; cin >> t;
    while (t--) {
        string arr_[9];
        for (int i=0; i<9; i++) cin >> arr_[i];

        int arr[9][9];
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                arr[i][j] = arr_[i][j] - '0';
                if (arr[i][j] == 1)
                    arr[i][j] = 2;

                cout << arr[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}

