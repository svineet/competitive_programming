#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool custom_compare(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first<b.first;
}

int binary_search(vector< pair<int, int> > array, int left, int right, int target) {
    if (right - left < 1) return -1;
    if (right - left == 1) {
        if (target == array[left].first)
            return array[left].second; // pair (cost, index)
        else
            return -1;
    }

    int mid = (left+right)/2;
    if (array[mid].first == target) {
        return array[mid].second;
    }
    else if (array[mid].first < target) {
        // Go right
        return binary_search(array, mid+1, right, target);
    }
    else {
        return binary_search(array, left, mid, target);
    }
}

int main() {
    std::ios::sync_with_stdio(0);

    int t;
    cin >> t;
    
    for (int cs=0; cs<t; cs++) {
        int m, n;
        cin >> m >> n;
        vector< pair<int, int> > array; 
        array.reserve(n);
        // Make an array of pairs
        // Pair (a, b) represents (cost, index)
        for (int i=1; i<=n; i++) {
            pair<int, int> temp;
            cin >> temp.first;
            temp.second = i;
            array.push_back(temp);
        }

        sort(array.begin(), array.end(), custom_compare);
        pair<int, int> taken;
        for (int i=0; i<n; i++) {
            // Act as if we took the current element;
            taken.first = array[i].second;
            int diff = m-array[i].first;
            int second;
            if (diff>array[i].first) {
                second = binary_search(array, i+1, n, diff);
            }
            else {
                second = binary_search(array, 0, i, diff);
            }
            if (second != -1) {
                taken.second = second;
                break;
            }
        }

        printf("%d %d\n", min(taken.first, taken.second),
                          max(taken.first, taken.second));
    }

    return 0;
}
