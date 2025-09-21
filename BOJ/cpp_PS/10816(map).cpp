#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n;
    unordered_map<int, int> card;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        card[temp]++;
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int find_card;
        cin >> find_card;
        cout << card[find_card] << " ";
    }
}