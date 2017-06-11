#include <bits/stdc++.h>
using namespace std;

struct Request {
    int people, money;
    int index;
};

int main() {
    int n; cin >> n;
    Request request[n];
    for (int i=0; i<n; i++) {
        cin >> request[i].people >> request[i].money;
        request[i].index = i+1;
    }

    sort (request, request+n,
          [] (Request a, Request b) {
              if (a.money == b.money) {
                  return a.people < b.people;
              } else {
                  return a.money > b.money;
              }
          });

    int m; cin >> m;
    pair<int, bool> tables[m];
    for (int i=0; i<m; i++) {
        cin >> tables[i].first;
        tables[i].second = false;
        // Not deleted.
    }

    list<pair<int, int>> orders;
    long long acreqs = 0,
              moneys = 0;
    for (int i=0; i<n; i++) {
        // Find the best table such that
        // it has capacity more than
        // current people required
        // and is the smallest one so.
        int mdex = -1;
        for (int j=0; j<m; j++) {
            if (request[i].people <= tables[j].first &&
                !tables[j].second) {
                if (mdex == -1)
                    mdex = j;
                else if (tables[j].first < tables[mdex].first)
                    mdex = j;
            }
        }

        if (mdex != -1) {
            orders.push_back({request[i].index, mdex+1});
            tables[mdex].second = true;
            acreqs++;
            moneys += request[i].money;
        }
    }

    cout << acreqs << " " << moneys << endl;
    for (pair<int, int> order: orders) {
        cout << order.first << " " << order.second << endl;
    }

    return 0;
}
