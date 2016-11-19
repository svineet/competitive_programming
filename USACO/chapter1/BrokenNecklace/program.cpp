/*
ID: saivine1
PROG: beads 
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int wrap_around(int given, int n) {
    int index = given;
    if (index < 0)
        index += n;
    if (index >= n)
        index = index - n;
        
    return index;
}

int main() {
    ofstream fout;
    fout.open("beads.out");
    ifstream fin;
    fin.open("beads.in");

    int n;
    fin >> n;
    string sequence;
    fin >> sequence;

    int maxdiff = -1000;
    for (int i=0; i<sequence.length(); i++) {
        int lindex = wrap_around(i-1, n);
        char lchar = sequence[lindex];
        int elemsseen=1;
        while (elemsseen<=n &&
               (sequence[lindex] == lchar || sequence[lindex] == 'w')) {
            lindex = wrap_around(lindex-1, n);
            elemsseen++;
        }
        lindex = wrap_around(lindex+1, n);
        //cout << lindex << " ; " << sequence[lindex] << endl;

        int rindex = wrap_around(i, n);
        char rchar = sequence[rindex];
        elemsseen++;
        while ((sequence[rindex] == rchar || sequence[rindex] == 'w')
                && rindex!=lindex) {
            rindex = wrap_around(rindex+1, n);
            elemsseen++;
        }
        rindex = wrap_around(rindex-1, n);
        cout << elemsseen << endl;
        //cout << rindex << " ; " << sequence[rindex] << endl;
        //cout << "------------------------" << endl;
        int cdiff = 0;
        if (rindex>lindex)
            cdiff = rindex-lindex+1;
        else
            cdiff = n-lindex+rindex+1;
        if (cdiff>maxdiff)
            maxdiff = cdiff;
    }
    fout << maxdiff << endl;
    
    return (0);
}
