#include <iostream>
#include <algorithm>
using namespace std;

bool compare_custom(const pair<int, int>& a,
                    const pair<int, int>& b) {
    return a>b;
}

int main() {
    int n, k;
    cin >> n >> k;
    pair<int, int> array[n];
    for (int i=0; i<n; i++) {
        pair<int, int> temp;
        cin >> temp.first >> temp.second; // <luck, importance>
        array[i] = temp;
    }
    sort (array, array+n, compare_custom);
    int taken_k=0, luck=0;
    for (int i=0; i<n; i++) {
        // cout << array[i].first << " " << array[i].second << endl;
        if (array[i].second == 1 && taken_k<k) {
            // We can afford to lose this one and gain luck
            luck += array[i].first;
            // cout << "+++++ " << array[i].first << endl;
            taken_k++;
        }
        else if (array[i].second == 1 && taken_k>=k) {
            // We have taken all important competitions we could
            // We have to win this one and lose luck
            luck -= array[i].first;
            // cout << "----- " << array[i].first << endl;
        }
        if (array[i].second == 0)
            luck += array[i].first; // Just take all unimportant competitions
    }
    cout << luck << endl;

    return 0;
}
