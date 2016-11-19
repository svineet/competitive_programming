#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int array[200000];
vector<int> adjlist[200000];
long long maximum=-1337000;

void DFS(int node, int parent, int best) {
    if (best-array[node]>maximum)
        maximum = best-array[node];

    if (array[node]>best)
        best = array[node];

    int len = adjlist[node].size();
    // Loop will run only once if only parent is present
    for (int i=0; i<len; i++) {
        if (adjlist[node][i] != parent) {
            DFS(adjlist[node][i], node, best);
        }
    }

    return;
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }
    int start = 0;
    for (int i=0; i<n; i++) {
        int parent; cin >> parent;
        if (parent == -1) {
            start = i;
            continue;
        }

        parent--;
        adjlist[parent].push_back(i);
        adjlist[i].push_back(parent);
    }

    DFS(start, -1, array[start]);
    // Start at hojo with no parent, and a best of 0
 
    cout << maximum << endl;

    return 0;
}
