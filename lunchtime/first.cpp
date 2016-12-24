#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t; cin >> t;
    for (int cs=0; cs<t; cs++) {
        long long matrix[3][3];
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                cin >> matrix[i][j];
            }
        }

        long long best=0;
        for (int i=0; i<3; i++) {
            long long rows=0, cols=0;
            for (int j=0; j<3; j++) {
                rows+=matrix[i][j];
                cols+=matrix[j][i];
            }
            if (rows%2==0)
                rows--;
            if (cols%2==0)
                cols--;
            best = max(best, max(rows, cols));
        }
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                long long t = matrix[i][j];
                if (t%2==0)
                    t--;
                best = max(t, best);
            }
        }
        cout << best << endl;
    }

    return 0;
}
