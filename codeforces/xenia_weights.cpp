#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool array[11];
int m;
vector<int> moves;

bool dfs(int balance, int parent, int moves_done) {
	if (moves_done == m) {
		cout << "YES" << endl;
		for (int i=0; i<moves.size(); i++) {
			cout << moves[i] << " ";
		}
		cout << endl;
		return true;
	}

	bool result = false;
	for (int i=1; i<=10; i++) {
		if (array[i] && i!=parent) {
			if (balance == 0) {
				moves.push_back(i);
				result = dfs(balance+i, i, moves_done+1);
				moves.pop_back();
			}
			else if (moves_done%2==0 && (balance+i)*balance<0) {
				moves.push_back(i);
				result = dfs(balance+i, i, moves_done+1);
				moves.pop_back();
			} else if ((balance-i)*balance<0) {
				moves.push_back(i);
				result = dfs(balance-i, i, moves_done+1);
				moves.pop_back();
			}

			if (result) return true;
		}
	}
	return result;
}

int main() {
	//freopen("sample.in", "r", stdin);
	
	string kilos; cin >> kilos;
	cin >> m;
	
	for (int i=1; i<=10; i++) {
		if (kilos[i-1]=='1')
			array[i] = true;
		else
			array[i] = false;
	}
	
	if (dfs(0, -1, 0)) {
		// GATEM
	} else {
		cout << "NO" << endl;
	}
	
	return 0;
}
