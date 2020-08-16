#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int A[n];
        for (int i=0; i<n; i++) cin >> A[i];

        int winner[n];
        winner[n-1] = 0; // Player wins
        for (int i=n-2; i>=0; i--) {
            /*
            if (A[i] > 1)
                winner[i] = winner[i+1];
            else
                winner[i] = 1-winner[i+1];
            */

            if (A[i] > 1 && winner[i+1] == 0)
                winner[i] = 0;
            if (A[i] == 1 && winner[i+1] == 0)
                winner[i] = 1;

            if (A[i] > 1 && winner[i+1] == 1)
                winner[i] = 0;
            if (A[i] == 1 && winner[i+1] == 1)
                winner[i] = 0;
        }

        if (winner[0] == 0)
            cout << "First\n";
        else
            cout << "Second\n";
    }

    return 0;
}

