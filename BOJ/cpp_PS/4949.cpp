#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool is_balanced(string s) {
    stack<char> stk;
    for (char ch : s) {
        if (ch == '(' || ch == '[') {
            stk.push(ch);
        } else if (ch == ')') {
            if (stk.empty() || stk.top() != '(') {
                return false;
            }
            stk.pop();
        } else if (ch == ']') {
            if (stk.empty() || stk.top() != '[') {
                return false;
            }
            stk.pop();
        }
    }
    return stk.empty();
}

int main() {
    string s;
    while (1) {
        getline(cin, s);
        if (s == ".") break;
        cout << (is_balanced(s) ? "yes" : "no") << '\n';
    }
    return 0;
}