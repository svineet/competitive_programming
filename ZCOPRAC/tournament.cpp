#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	// freopen("sample.in", "r", stdin);
	
	int n; cin >> n;
	int array[n];
	for (int i=0; i<n; i++) {
		cin >> array[i];
	}
	sort(array, array+n);
	
	long long sum = 0;
	int i=0;
	for (long long mult=1-n; mult<=(n-1); mult+=2) {
		sum += mult*array[i];
		i++;
	}
	cout << sum << endl;
	
	return 0;
}
