#include <algorithm>
#include <iostream>

using namespace std;
int dp[50001];

int main() {
    int n;
    cin >> n;

    dp[0] = 0;  // i가 1일때를 위해.
    for (int i = 1; i <= n; i++) {
        dp[i] = 4;  // 4로 해도 되나, i가 프로그램 상 더 안정적(50000이상인 경우우)
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    cout << dp[n] << '\n';
    return 0;
}