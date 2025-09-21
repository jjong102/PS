#include <iostream>
#include <stack>

using namespace std;

bool is_VPS(string s) {
    stack<char> stk;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            stk.push('(');
        } else if (s[i] == ')') {
            if (stk.empty() || stk.top() != '(') {
                return false;
            }
            stk.pop();
        }
    }
    return stk.empty();
}

int main() {
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        cout << (is_VPS(s) ? "YES" : "NO") << endl;
    }

    return 0;
}