// value값으로 map을 돌면 시간 복잡도 O(n)이다.
// find_if O(n)
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ostringstream out;

    int n, m;
    cin >> n >> m;

    unordered_map<int, string> enc;
    unordered_map<string, int> renc;
    for (int i = 1; i <= n; i++) {
        string temp;
        cin >> temp;
        enc.insert({i, temp});
        renc.insert({temp, i});
    }

    for (int i = 0; i < m; i++) {
        string temp;
        cin >> temp;
        bool isInt = all_of(temp.begin(), temp.end(), ::isdigit);
        if (isInt) {
            out << enc[stoi(temp)] << '\n';
        } else {
            out << renc[temp] << '\n';
        }
    }

    cout << out.str();
    return 0;
}