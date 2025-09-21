// perfix_sum으로도 해결 가능하지만, 이게 더 효과적.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int n;
    ll take_wood;
    cin >> n >> take_wood;

    vector<ll> woods(n);
    for (int i = 0; i < n; i++) {
        cin >> woods[i];
    }

    ll result = 0;
    ll start = 0;
    ll end = *max_element(woods.begin(), woods.end());

    while (start <= end) {
        ll len = 0;
        ll mid = (start + end) / 2;

        for (int i = 0; i < n; i++) {
            if (woods[i] > mid) {
                len += (woods[i] - mid);
            }
        }

        // 조건에 맞는 최대 값을 찾아야 하기 때문에
        // result값 계속 갱신해줌.
        if (len >= take_wood) {
            result = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << result << '\n';
    return 0;
}