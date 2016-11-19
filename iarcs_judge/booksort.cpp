#include <iostream>
#include <algorithm>
using namespace std;

int main() {	
	//freopen("sample.in", "r", stdin);
	int n; cin >> n;
	int array[n];
	for (int i=0; i<n; i++) {
		cin >> array[i];
	}
	
	int lis[n];

	lis[0] = 1;
	for (int i=1; i<n; i++) {
		lis[i] = 1;
		for (int j=0; j<i; j++) {
			if (array[j]<array[i])
				lis[i] = max(lis[i],
							 lis[j]+1);
		}
	}
	cout << n-*max_element(lis, lis+n) << endl;

	return 0;
}
