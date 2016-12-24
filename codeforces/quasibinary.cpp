#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<int> quasis;
	quasis.reserve(64);
	for (int i=1; i<=64; i++) {
		int result = 0;
		// Extracting binary digits
		int multiplier = 1;
		for (int j=0; j<=6; j++) {
			result += multiplier*((1<<j)&i?1:0);
			multiplier*=10;
		}
		quasis.push_back(result);
		//printf("%d\n", result);
	}
	
	int dp[n+1];
	int parent[n+1];
	dp[0] = parent[0] = 0;
	for (int i=1; i<=n; i++) {
		dp[i] = 1e8;
		for (int j=0; j<quasis.size(); j++) {
			if (quasis[j]>i) break;
			
			if (dp[i]>dp[i-quasis[j]]+1) {
				parent[i] = quasis[j];
				dp[i] = dp[i-quasis[j]]+1;
			}
		}
	}
	printf("%d\n", dp[n]);
	int x = n;
	while (parent[x] != 0) {
		printf("%d ", parent[x]);
		x -= parent[x];
	}
	printf("\n");
	
	
	return 0;
}
