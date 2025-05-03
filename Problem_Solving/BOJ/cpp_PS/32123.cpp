#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

using namespace std;
using vi = vector<int>;
int MAX = 0;
int boring(string s, int N) {
    int max = 0;
    for (int i = 0; i < 2 * N; i++) {
        for (int j = i; j < 2 * N; j++) {
            string split = s.substr(i, j - i + 1);
            int count_0 = 0;
            int count_1 = 0;
            for (char k : split) {
                if (k == '0') {
                    count_0++;
                } else {
                    count_1++;
                }
                int result = (int) abs(count_0 - count_1);
                if (max < result) {
                    max = result;
                }
            }
        }
    }
    MAX = max;
    return max;
}

int main() {
    FASTIO;

    int N, K;
    string s;
    vi v_cost;

    cin >> N >> K >> s;

    for (int i = 0; i < 2 * N - 1; i++) {
        int cost = 0;
        string temp = s;
        for (int j = i; j < 2 * N - 1; j++) {
            if (temp[j] != temp[j + 1]) {
                swap(temp[j], temp[j + 1]);
                cost++;
                if (K == boring(temp, N)) {
                    v_cost.push_back(cost);
                }
            }
        }
    }

    if (v_cost.empty()) {
        cout << 0 << endl;
    } else {
        cout << *min_element(v_cost.begin(), v_cost.end()) << endl;
    }
}
