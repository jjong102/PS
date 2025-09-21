// Bottom-Up *지금은 이게 더 좋음.
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
constexpr int R = 10007;
int main() {
    int n;
    cin >> n;
    vector<ll> dp(n + 1);
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] % R + 2 * (dp[i - 2]) % R) % R;
    }
    cout << dp[n] << '\n';
    return 0;
}

// 메모이제이션 코드 (Top-Down)
// 희송 상태 DP인 경우 Top-Down방식 유용.
#if 0
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
constexpr int R = 10007;

vector<ll> dp(1001, -1);  // -1: 아직 계산 안 된 상태

ll tile(int n) {
    if (n == 1) return 1;
    if (n == 2) return 3;
    if (dp[n] != -1) return dp[n];  // 이미 계산된 값이면 반환

    return dp[n] = (tile(n - 1) + 2 * tile(n - 2)) % R;
}

int main() {
    int n;
    cin >> n;
    cout << tile(n) << '\n';
    return 0;
}
#endif