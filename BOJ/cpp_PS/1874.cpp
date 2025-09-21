#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int pri_max_pop = 0;
    int want_pop;
    int index = 0;

    stack<int> stk;
    vector<char> result;

    for (int i = 0; i < n; i++) {
        cin >> want_pop;
        if (want_pop > pri_max_pop) {
            int push_num = want_pop - pri_max_pop;
            for (int j = 0; j < push_num; j++) {
                index++;
                stk.push(index);
                result.push_back('+');
            }
            stk.pop();
            pri_max_pop = (pri_max_pop > index) ? pri_max_pop : index;
            result.push_back('-');
        } else {
            if (stk.top() == want_pop) {
                stk.pop();
                pri_max_pop = (pri_max_pop > index) ? pri_max_pop : index;
                result.push_back('-');
            } else {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }

    return 0;
}