#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	//freopen("sample.in", "r", stdin);
	int n;
	while (cin >> n) {
		int mixtures[n];
		for (int i=0; i<n; i++) {
			cin >> mixtures[i];
		}
		
		int dp[n][n];
		// Best smoke achievable for A[i..j]
		int resmix[n][n];
		// The resultant mixtures we get after
		// mixing A[i..j] optimally.
		
		for (int i=0; i<n; i++) {
			dp[i][i] = 0;
			resmix[i][i] = mixtures[i];
			// No smoke, resultant of one mixture
			// is the mixture itself.
		}
		
		for (int subsize=2; subsize<=n; subsize++) {
			for (int i=0; i<=(n-subsize); i++) {
				int j = i+subsize-1;
				dp[i][j] = 1e8;
				for (int k=i; k<j; k++) {
					int hypo = dp[i][k]+dp[k+1][j]+resmix[i][k]*resmix[k+1][j];
					if (hypo<dp[i][j]) {
						resmix[i][j] = (resmix[i][k]+resmix[k+1][j])%100;
						dp[i][j] = hypo;
					}
				}
			}
		}
		cout << dp[0][n-1] << endl;
	}
}
