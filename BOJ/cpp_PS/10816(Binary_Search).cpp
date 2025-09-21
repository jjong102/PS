// 이거 시간초과 남.
// distance함수가 O(n)임.
// 결국 O(n^2)되면서 컷컷

#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    multiset<int> card;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        card.insert(temp);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int find_card;
        cin >> find_card;
        int index = distance(lower_bound(card.begin(), card.end(), find_card),
                             upper_bound(card.begin(), card.end(), find_card));
        cout << index << " ";
    }

    return 0;
}