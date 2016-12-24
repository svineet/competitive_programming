#include <bits/stdc++.h>
using namespace std;

int n;
char A[1010], B[1010];
int memo[1011][1011][3];
int move[1011][1011][3];
bool solve(int i, int j, int diff) {
    if (diff<-1 || diff>1) return false;
    if (memo[i][j][diff+1] != -1)
        return memo[i][j][diff+1];


    if (i==0 && j==0) {
        memo[i][j][diff+1] = true;
        move[i][j][diff+1] = -1;
        return memo[i][j][diff+1];
    }

    if (i==0) {
        if (B[j-1] == '1') {
            memo[i][j][diff+1] = solve(i, j-1, diff+1);
        } else {
            memo[i][j][diff+1] = solve(i, j-1, diff-1);
        }
        move[i][j][diff+1] = 2;
        return memo[i][j][diff+1];
    } else if (j==0) {
        if (A[i-1] == '1') {
            memo[i][j][diff+1] = solve(i-1, j, diff+1);
        } else {
            memo[i][j][diff+1] = solve(i-1, j, diff-1);
        }
        move[i][j][diff+1] = 1;
        return memo[i][j][diff+1];
    }

    if (A[i-1] == '1') {
        memo[i][j][diff+1] = solve(i-1, j, diff+1);
        if (memo[i][j][diff+1]) {
            move[i][j][diff+1] = 1;
            return true;
        }
    } else {
        memo[i][j][diff+1] = solve(i-1, j, diff-1);
        if (memo[i][j][diff+1]) {
            move[i][j][diff+1] = 1;
            return true;
        }
    }
    if (B[j-1] == '1') {
        memo[i][j][diff+1] = solve(i, j-1, diff+1);
        if (memo[i][j][diff+1]) {
            move[i][j][diff+1] = 2;
            return true;
        }
    } else {
        memo[i][j][diff+1] = solve(i, j-1, diff-1);
        if (memo[i][j][diff+1]) {
            move[i][j][diff+1] = 2;
            return true;
        }
    }

    memo[i][j][diff+1] = false;
    return false;
}

int main() {
    cin >> n >> A >> B;
    reverse(A, A+n); reverse(B, B+n);
    for (int i=0; i<1001; i++)
        for (int j=0; j<1001; j++)
            for (int k=0; k<3; k++)
                memo[i][j][k] = move[i][j][k] = -1;

    bool yes = solve(n, n, 0);
    if (yes) {
        int diff = 0;
        int i = n, j = n;
        while (!(j==0 && i==0)) {
            //cout << i << " " << j << endl;
            cout << move[i][j][diff+1];
            if (move[i][j][diff+1] == 1) {
                if (A[i-1] == '1') diff++;
                else             diff--;
                i--;
            } else {
                if (B[j-1] == '1') diff++;
                else             diff--;
                j--;
            }
        }
        cout << endl;
    } else {
        cout << "Impossible" << endl;
    }
}
