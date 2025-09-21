#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int k, n;
    cin >> k >> n;

    vector<ll> len(k);
    for (int i = 0; i < k; i++) {
        cin >> len[i];
    }

    ll start = 1;
    ll end = *max_element(len.begin(), len.end());
    ll result = 0;

    while (start <= end) {
        ll mid = (start + end) / 2;
        ll num_sum = 0;

        for (int i = 0; i < k; i++) {
            num_sum += len[i] / mid;
        }

        if (num_sum >= n) {
            result = mid;     // 가능한 길이 저장
            start = mid + 1;  // 더 긴 길이 시도
        } else {
            end = mid - 1;  // 더 짧은 길이로 시도
        }
    }

    cout << result << '\n';
    return 0;
}