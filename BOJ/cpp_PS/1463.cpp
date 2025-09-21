#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int min_oper_num[n];
    min_oper_num[1] = 0;

    for (int i = 2; i <= n; i++) {
        // -1을 빼는 연산.
        min_oper_num[i] = min_oper_num[i - 1] + 1;

        // 2를 나눠주는 연산.
        if (i % 2 == 0) {
            min_oper_num[i] = min(min_oper_num[i], min_oper_num[i / 2] + 1);
        }

        // 3을 나눠주는 연산.
        if (i % 3 == 0) {
            min_oper_num[i] = min(min_oper_num[i], min_oper_num[i / 3] + 1);
        }
    }

    cout << min_oper_num[n] << '\n';
    return 0;
}