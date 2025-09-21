// 개선점
//   1. 입력 받을때 sum을 구하자
//   2. 입력 받을때 freq[num[i]]++; 이거 사용하면 키 값에 자동으로 빈도수 들어감
//   3. 최빈값 대대적인 수정 필요요

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    // 산술 평균
    double mean = 0;
    for (int i = 0; i < n; i++) {
        mean += num[i];
    }
    int result = round(mean / n);
    if (result == -0) {
        cout << 0 << '\n';
    } else {
        cout << result << '\n';
    }

    // 중앙값
    sort(num.begin(), num.end());
    cout << num[n / 2] << '\n';

    // 최빈값
    multimap<int, int> frequencyMap;
    for (int i = 0; i < n; i++) {
        if (num[i] == num[i - 1]) {
            continue;
        }
        int frequency = 0;
        auto it = equal_range(num.begin(), num.end(), num[i]);
        frequency = it.second - it.first;
        frequencyMap.insert({frequency, num[i]});
    }

    vector<int> values;
    auto max_frequency = frequencyMap.rbegin()->first;
    auto range = frequencyMap.equal_range(max_frequency);
    for (auto it = range.first; it != range.second; ++it) {
        values.push_back(it->second);
    }
    sort(values.begin(), values.end());

    int secondMin;
    if (values.size() >= 2) {
        secondMin = values[1];
    } else {
        secondMin = values[0];
    }
    cout << secondMin << '\n';

    // 최빈값 수정시 아이디어
    //   1. 최대 빈도수를 찾아요 (max_element활용, 람다 활용)
    //   2. 최대 반도수의 값들을 벡터에 모아줌. (for (const auto& [val, count] : freq) 활용)
    //   3. 이제 두번째로 작은 값 찾아주면 됩니다.

    // 범위
    cout << num[n - 1] - num[0] << '\n';
    return 0;
}