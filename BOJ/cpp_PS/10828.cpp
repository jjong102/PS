#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    stack<int> stk;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "push") {
            int temp;
            cin >> temp;
            stk.push(temp);
        } else if (s == "top") {
            if (!stk.empty())
                cout << stk.top() << endl;
            else
                cout << -1 << endl;
        } else if (s == "size") {
            cout << stk.size() << endl;
        } else if (s == "empty") {
            if (!stk.empty())
                cout << 0 << endl;
            else
                cout << 1 << endl;
        } else if (s == "pop") {
            if (!stk.empty()) {
                cout << stk.top() << endl;
                stk.pop();
            } else
                cout << -1 << endl;
        }
    }
    return 0;
}