#include <iostream>
#include <algorithm>
using namespace std;

bool can(int m, int s) {
    return s>=0 && s<=9*m;
}

int main() {
    int m, sum; cin >> m >> sum;
    int sum2 = sum;
    string lowest = "", highest = "";
    if (m==0) {
        cout << "-1 -1" << endl;
        return 0;
    }
    if (m==1 && sum == 0) {
        cout << "0 0" << endl;
        return 0;
    }

    bool okay = true;
    for (int i=0; i<m; i++) {
        bool didit = false;
        for (int j=0; j<10; j++) {
            if (i==0 && j==0) continue;

            char d = char('0'+j);
            if (can(m-i-1, sum-j)) {
                lowest += d;
                sum -= j;
                didit = true;
                break;
            }
        }

        if (!didit) {
            okay = false;
            break;
        }
    }
    if (!okay)
        cout << "-1";
    else
        cout << lowest;

    cout << " ";
    okay = true;
    sum = sum2;
    for (int i=0; i<m; i++) {
        bool didit = false;
        for (int j=9; j>=0; j--) {
            if (i==0 && j==0) continue;

            char d = char('0'+j);
            if (can(m-i-1, sum-j)) {
                highest += d;
                sum -= j;
                didit = true;
                break;
            }
        }

        if (!didit) {
            okay = false;
            break;
        }
    }

    if (!okay)
        cout << "-1";
    else
        cout << highest;
    cout << endl;

    return 0;
}
