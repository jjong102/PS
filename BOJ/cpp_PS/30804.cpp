#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    unordered_map<int, int> count;
    int left = 0, right = 0;
    int max_len = 0;

    while (right < n) {
        count[v[right]]++;

        while (count.size() > 2) {
            count[v[left]]--;
            if (count[v[left]] == 0) count.erase(v[left]);
            left++;
        }

        max_len = max(max_len, right - left + 1);
        right++;
    }

    cout << max_len << '\n';
    return 0;
}