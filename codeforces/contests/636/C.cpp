#include <bits/stdc++.h>
using namespace std;


int main(int argc, char **argv) {
    int t; cin >> t;
    while (t--) {
        long long n; cin >> n;
        long long arr[n];
        for (int i=0; i<n; i++) cin >> arr[i];

        int pos_segment = (arr[0] > 0);
        long long segment_mex = arr[0];
        long long result = 0;

        for (int i=0; i<n; i++) {
            // Check if segment sign changed, start a new segment
            if (pos_segment == 1 && arr[i] < 0) {
                result += segment_mex;

                segment_mex = arr[i];
                pos_segment = 1 - pos_segment;
            } else if (pos_segment == 0 && arr[i] > 0) {
                result += segment_mex;

                segment_mex = arr[i];
                pos_segment = 1 - pos_segment;
            } else {
                segment_mex = max(segment_mex, arr[i]);
            }

        }

        result += segment_mex;
        cout << result << endl;
    }

    return 0;
}

