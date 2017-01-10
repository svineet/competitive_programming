#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
    int tdist;
};

int main() {
    int n; cin >> n;
    string str; cin >> str;

    queue<point> past;
    point prev; prev.x = 0; prev.y = 0;
    prev.tdist = 0;

    int totpoints = 1;
    // The last point is always
    // a destination.
    point current;
    current.x = 0; current.y = 0; current.tdist = 0;
    for (int i=0; i<n; i++) {
        point oldcur;
        oldcur.x = current.x;
        oldcur.y = current.y;
        oldcur.tdist = current.tdist;
        if (str[i] == 'R') {
            current.x++;
        } else if (str[i] == 'L') {
            current.x--;
        } else if (str[i] == 'U') {
            current.y++;
        } else if (str[i] == 'D') {
            current.y--;
        }
        current.tdist++;

        if (abs(current.x-prev.x)+abs(current.y-prev.y) != current.tdist-prev.tdist) {
            /*cout << current.x << " " << current.y << endl;
            cout << prev.x << " " << prev.y << endl;
            cout << endl;*/
            prev = oldcur;

            totpoints++;
        }
    }

    cout << totpoints << endl;

    return 0;
}
