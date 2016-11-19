#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	//freopen("sample.in", "r", stdin);
	
	int n; int h;
	cin >> n >> h;
	int array[n];
	for (int i=0; i<n; i++) {
		cin >> array[i];
	}
	
	int index=0;
	int carrying=0;
	while (true) {
		int command; cin >> command;
		if (command == 0) {
			break;
		}
		
		switch (command) {
			case 1:
				if (index>0) index--;
				break;
			
			case 2:
				if (index<n-1) index++;
				break;
			
			case 3:
				if (carrying != 1 && array[index]>0) {
					carrying = 1;
					array[index]--;
				}
				break;
			
			case 4:
				if (carrying && array[index]<h) {
					carrying = 0;
					array[index]++;
				}
				break;
		}
	}
	
	for (int i=0; i<n; i++) {
		cout << array[i];
		if (i==n-1)
			cout << endl;
		else
			cout << " ";
	}
	
	return 0;
}
