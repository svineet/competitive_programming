#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
vector<int> adjlist[200000];
int cats[200000];
int n, m;
 
int DFS(int node, int parent, int cats_seen) {
    /*cout << "Exploring: " << node+1 << endl;
    cout << cats_seen << endl;*/
    if (cats_seen > m)
        return 0;
 
    int len = adjlist[node].size();
    if (len == 1 && adjlist[node][0] == parent && cats_seen<=m)
        return 1;
 
    int sum = 0;
    for (int i=0; i<len; i++) {
        int has_cat = cats[adjlist[node][i]];
        if (adjlist[node][i] != parent)
            sum += DFS(adjlist[node][i], node, (has_cat?has_cat+cats_seen:0));
    }
    return sum;
}
 
int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> cats[i];
    }
    for (int i=0; i<n-1; i++) {
        int source, dest; cin >> source >> dest;
        source--; dest--;
        adjlist[source].push_back(dest);
        adjlist[dest].push_back(source);
    }
    cout << DFS(0, -1, (cats[0]?1:0)) << endl;
 
    return 0;
}
