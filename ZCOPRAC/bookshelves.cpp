#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int A[n], B[n];

    for (int i=0; i<n; i++) {
        cin >> A[i];
    }
    for (int i=0; i<n; i++) {
        cin >> B[i];
    }

    sort (A, A+n);
    sort (B, B+n);

    int skew = A[n-1]+B[n-1];
    for (int pos=1; pos<=k; pos++) {
        int abig = max(A[n-1], B[n-1])+max(A[pos-1], B[n-pos-1]);
        int bbig = max(A[n-1], B[n-1])+max(B[pos-1], A[n-pos-1]);
        skew = min(skew, min(abig, bbig));
    }
    cout << skew << endl;
}
