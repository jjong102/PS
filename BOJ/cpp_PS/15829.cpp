#include <cmath>
#include <iostream>
#include <string>
#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
using namespace std;
using ll = long long;
constexpr int MOD = 1234567891;
/*
<수학적 mod 분배법칙>
1. (a + b) mod m = ((a%m) + (b%m))%m
2. (a - b) mod m = ((a%m) - (b%m) + m)%m [+m 필수]
3. (a * b) mod m = ((a%m) * (b%m))%m
4. 중복되는 % mod : 연산에 영향 없음.
*/
ll value(char a);

int main() {
    FASTIO;
    ll l = 0;
    string s;
    cin >> l >> s;

    ll r = 1;
    ll hash = 0;
    for (int i = 0; i < l; i++) {
        ll v = value(s[i]);
        hash = (hash + v * r % MOD) % MOD;
        r = (r * 31) % MOD;
    }

    cout << hash << endl;
}

ll value(char a) {
    ll v = a - 'a' + 1;
    return v;
}