#include <iostream>
#include <algorithm>
using namespace std;

int best_game_ign(int array[], int left, int right, int partials[]) {
    if (right-left <= 1) return 0;
    for (int i=left+1; i<right; i++) {
        int left_sum = partials[i-1]-(left==0?0:partials[left-1]),
            right_sum = partials[right-1]-partials[i-1];
        // cout << "At: " << i << " sum left: " << left_sum << "; " << right_sum << endl;
        if (left_sum == right_sum) {
            // cout << "Cutting at: " << i << endl;
            return 1+max(best_game_ign(array, left, i, partials),
                       best_game_ign(array, i, right, partials));
        }
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    for (int cs=0; cs<t; cs++) {
        int n;
        cin >> n;
        int array[n]; int partials[n];
        for (int i=0; i<n; i++) {
            cin >> array[i];
            if (i!=0)
                partials[i] = partials[i-1] + array[i];
            else
                partials[i] = array[i];
        }

        cout << best_game_ign(array, 0, n, partials) << endl;
    }

    return 0;
}
