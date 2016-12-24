#include <bits/stdc++.h>
using namespace std;

int n;
int array[3001];
vector<int> result;

void solve(int left, int right) {
    if (right<left) return;
    if (right == left) {
        result.push_back(array[left]);
        return;
    }

    if (array[left]>array[right]) {
        // All segment elements belong to the right
        solve (left, right-1);
    } else if (array[right-1]<array[right]) {
        // All segment elements belong to the left
        solve (left, right-1);
    } else {
        // Find index j such that left..j is less than
        // pivot and j+1..right-1 is more than pivot
        int indice = -1;
        for (int i=left; i<right; i++) {
            if (array[i]<array[right] && array[i+1]>array[right]) {
                indice = i; break;
            }
        }
        solve (indice+1, right-1);
        solve (left, indice);
    }

    result.push_back(array[right]);
}

int main() {
    cin >> n;
    result.reserve(n);
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }

    solve(0, n-1);

    for (int i=0; i<n; i++)
        cout << result[i] << endl;

    return 0;
}
