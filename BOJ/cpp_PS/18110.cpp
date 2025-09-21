// 이 문제 정석은 vector에 넣고 sort한다음, cotoff만큼 앞뒤로 잘라서 for문 돌리기

#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    int cutoff = round((double) 0.15 * n);
    multiset<int> score;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        score.insert(temp);
    }

    auto remove_start = prev(score.end(), cutoff);
    score.erase(remove_start, score.end());

    auto remove_end = next(score.begin(), cutoff);
    score.erase(score.begin(), remove_end);

    cout << round((double) accumulate(score.begin(), score.end(), 0) / score.size()) << endl;
    return 0;
}