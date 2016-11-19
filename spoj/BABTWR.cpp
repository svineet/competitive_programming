#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct triplet {
    int height, width, depth;
};

bool custom_compare(const triplet& a,
                    const triplet& b) {
    return make_pair(a.width, a.depth)>make_pair(b.width, b.depth);
}

int main() {
    while (true) {
        int n; cin >> n;
        if (n==0) break;
        vector<triplet> array;
        array.reserve(n);
        for (int i=0; i<n; i++) {
            int temp[3];
            cin >> temp[0] >> temp[1] >> temp[2];
            sort(temp, temp+3); // Generate lowest permutation
            do {
                triplet kek;
                kek.height = temp[0];
                kek.width = temp[1];
                kek.depth = temp[2];
                array.push_back(kek);
            } while (next_permutation(temp, temp+3)); // Add each perm
        }
        int length = array.size();
        sort(array.begin(), array.end(), custom_compare);
        /*for (int i=0; i<length; i++) {
            cout << array[i].height << " " << array[i].width << " " <<
                array[i].depth << endl;
        }*/
        int dp[length];
        dp[0] = array[0].height;
        //cout << dp[0] << " ";
        // dp[i] is the height of the tower last including i in a[0..i]
        for (int i=1; i<length; i++) {
            dp[i] = 0;
            for (int j=0; j<i; j++) {
                if (array[j].width>array[i].width &&
                        array[j].depth>array[i].depth) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i] += array[i].height;
            //cout << dp[i] << " ";
        }
        //cout << endl;
        cout << *max_element(dp, dp+length) << endl;
    }
    return 0;
}
