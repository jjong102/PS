// count 정렬입니다.

#include <iostream>
#include <vector>
#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
using namespace std;
using vi = vector<int>;
constexpr int MAX = 10001;

int main() {
    FASTIO;

    int N;
    cin >> N;
    vi count(MAX, 0);
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        count[temp]++;
    }

    for (int i = 0; i <= 10000; i++) {
        while (count[i]--) {
            cout << i << endl;
        }
    }
}
