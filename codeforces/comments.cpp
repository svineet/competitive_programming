#include <bits/stdc++.h>
using namespace std;

char str[1000010];
int n;
vector< pair<string, int> > 

vector<string> split(const char *str, char c = ' ')
{
    vector<string> result;

    do
    {
        const char *begin = str;

        while(*str != c && *str)
            str++;

        result.push_back(string(begin, str));
    } while (0 != *str++);

    return result;
}

int main() {
    cin >> str;
    n = strlen(str);

    return 0;
}
