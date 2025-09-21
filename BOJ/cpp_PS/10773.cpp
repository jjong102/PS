#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> stk;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        if (temp == 0) {
            stk.pop();
        } else {
            stk.push(temp);
        }
    }

    int result = 0;
    while (!stk.empty()) {
        result += stk.top();
        stk.pop();
    }

    cout << result << endl;

    return 0;
}