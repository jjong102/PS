#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    vector<int> sum(n);
    sum[0] = v[0];
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + v[i];
    }

    cout << accumulate(sum.begin(), sum.end(), 0) << '\n';
    return 0;
}