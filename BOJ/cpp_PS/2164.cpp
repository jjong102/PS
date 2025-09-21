#include <deque>
#include <iostream>

using namespace std;
using di = deque<int>;

#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

int main() {
    FASTIO;

    int n;
    cin >> n;
    di card;
    for (int i = 1; i <= n; i++) {
        card.push_back(i);
    }

    while (card.size() > 1) {
        card.pop_front();
        card.push_back(card.front());
        card.pop_front();
    }
    cout << card.front() << '\n';

    return 0;
}