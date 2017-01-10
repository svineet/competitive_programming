#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << fixed << setprecision(3);

    int stones; cin >> stones;
    int cse = 1;
    while (stones != 0) {
        double adjm[stones+1][stones+1];
        pair<double, double> stn[stones+1];
        for (int i=1; i<=stones; i++) {
            double x, y; cin >> x >> y;
            stn[i] = {x, y};
        }

        for (int i=1; i<=stones; i++) {
            for (int j=1; j<=stones; j++) {
                if (i==j) {
                    adjm[i][j] = 0;
                } else {
                    adjm[i][j] = sqrt(pow((stn[i].first-stn[j].first), 2)+
                                      pow((stn[i].second-stn[j].second), 2));
                }
            }
        }

        for (int k=1; k<=stones; k++) {
            for (int i=1; i<=stones; i++) {
                for (int j=1; j<=stones; j++) {
                    adjm[i][j] = min(adjm[i][j], max(adjm[i][k], adjm[k][j]));
                }
            }
        }

        cout << "Scenario #" << cse << endl;
        cout << "Frog Distance = " << adjm[1][2] << endl << endl;

        cin >> stones;
        cse++;
    }

    return 0;
}
