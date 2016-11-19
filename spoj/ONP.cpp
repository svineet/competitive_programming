#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string input; cin >> input;
        int n = input.length();
        stack<string> processed;
        stack<char> operators_stack;

        for (int i=0; i<n; i++) {
            if (input[i] == '(')
                continue;

            if (input[i] == '+' || input[i] == '-' ||
                input[i] == '*' || input[i] == '/' ||
                input[i] == '^') {
                operators_stack.push(input[i]);
                continue;
            }

            if (input[i] == ')') {
                string second = processed.top();
                processed.pop();
                string first = processed.top();
                processed.pop();
                char op = operators_stack.top();
                operators_stack.pop();
                processed.push(first+second+string(1, op));
                continue;
            }

            processed.push(string(1, input[i]));
        }
        cout << processed.top() << endl;
    }
    return 0;
}
