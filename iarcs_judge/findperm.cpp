#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	freopen("sample.in", "r", stdin);

	int n; cin >> n;
	int inversions[n+1]; // # inversions of (i+1) valued element
	int result[n] = {0};
	for (int i=1; i<=n; i++) {
		cin >> inversions[i];
	}
	
	for (int i=n-1; i>0; i--) {
		int number = i+1;
		cout << "Setting: " << number << " to: " << number-1-inversions[number] << endl;
		result[number-1-inversions[number]] = number;
	}

	for (int i=0; i<n; i++) {
		//if (result[i])
			cout << result[i] << " ";
		//else
		//	cout << "1 ";
	}
	cout << endl;
	
	
	return 0;
}
