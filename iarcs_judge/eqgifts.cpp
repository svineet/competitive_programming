#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	//freopen("sample.in", "r", stdin);
	int n; cin >> n;
	pair<int, int> books[n];
	long totalsum = 0;
	for (int i=0; i<n; i++) {
		cin >> books[i].first >> books[i].second;
		totalsum += books[i].first + books[i].second;
	}
	//cout << totalsum << endl;
	
	int dp[2][totalsum+1];
	// dp[i][j] indicates if using only
	// books from a[0..i] we can get a
	// sum of j.
	// We are looking dp[n][x]
	// such that totalsum-2*x is as close
	// to zero as possible.
	dp[0][0] = 1;
	dp[1][0] = 0;
	// 0 elements, 0 sum, possible.
	for (int i=1; i<=totalsum; i++) {
		dp[0][i] = 0;
		// Cannot create any sum using
		// no elements
	}


	
	int source = 0, dest = 1;
	for (int i=1; i<=n; i++) {
		if (i!=1)
			dp[source][0] = 0;

		for (int j=1; j<=totalsum; j++) {
			dp[dest][j] = 0;
			if (j-books[i-1].first>=0 && dp[source][j-books[i-1].first] == 1)
				dp[dest][j] = 1;
			if (j-books[i-1].second>=0 && dp[source][j-books[i-1].second] == 1)
				dp[dest][j] = 1;

			// We either use the first book and see
			// if we can make the sum
			// left over using a[0..i]
			// or try a similar strat for second
			// book
			
			//cout << dp[dest][j] << " ";
		}
		//cout << endl;

		swap(source, dest);
	}
	
	long long best = 1e10;
	for (int i=1; i<=totalsum; i++) {
		if (dp[source][i] == 1 && abs(totalsum-2*i)<best) {
			// If it is possible to make
			// this sum
			// We try to find the difference
			// it results in and select the best
			// out of all possible ones.
			best = abs(totalsum-2*i);
		}
	}
	cout << best << endl;
	

	return 0;
}
