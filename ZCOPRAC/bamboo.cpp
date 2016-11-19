#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int occurs_at[1000005];
    int array[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }
    sort (array, array+n);
    for (int i=0; i<n; i++) {
        occurs_at[array[i]] = i;
        // Note where it occurs at
        // for the sorted array
    }

    int best_count = (n>=2?2:1);
    int cur_count = 0;
    int cur_diff = 0;
    for (int i=0; i<n-1; i++) {
        cur_count = 1;
        for (int j=i+1; j<n; j++) {
            cur_diff = array[j]-array[i];
            cur_count = 2;
            int last = j;
            while (true) {
                if (occurs_at[array[last]+cur_diff] != 0) {
                    // It occurs somewhere
                    last = occurs_at[array[last]+cur_diff];
                    // get index of next element using map
                    cur_count++;
                }
                else {
                    break;
                }
            }
            if (cur_count > best_count)
                best_count = cur_count;
        }
    }
    cout << best_count << endl;
}
