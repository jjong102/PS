#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
constexpr int REMAIN = 10007;
int main() {
    int n;
    cin >> n;
    vector<ll> dp(1001);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= 1000; i++) {
        dp[i] = (dp[i - 1] % REMAIN + dp[i - 2] % REMAIN) % REMAIN;
    }

    cout << dp[n] << '\n';
    return 0;
}