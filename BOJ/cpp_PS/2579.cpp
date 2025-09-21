// 만약, 조금 더 진화 시킨다면..
//  1. jump랑 next*2의 크기를 비교하면 됨. -> 1개의 vector로 처리 가능.
//  2. dp[i] = max(dp[i - 2] + s[i], dp[i - 3] + s[i - 1] + s[i]);

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> stairs(n);
    for (int i = 0; i < n; i++) {
        cin >> stairs[i];
    }

    vector<int> max_nextjump(n);
    vector<int> max_jump(n);

    if (n == 1) {
        cout << stairs[0] << '\n';
        return 0;
    }

    // 아님 여기에 n>=1일때 부터 초기화하게 if문으로 감싸도 됨.
    max_nextjump[0] = stairs[0];
    max_jump[0] = 0;
    max_nextjump[1] = stairs[1];
    max_jump[1] = max_nextjump[0] + stairs[1];

    for (int i = 2; i <= n - 1; i++) {
        max_nextjump[i] = max(max_nextjump[i - 2], max_jump[i - 2]) + stairs[i];
        max_jump[i] = max_nextjump[i - 1] + stairs[i];
    }

    cout << max(max_nextjump[n - 1], max_jump[n - 1]) << '\n';

    return 0;
}