#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using vs = vector<string>;

int main() {
    int N;
    cin >> N;
    vector<vs> s(51);
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        int len = temp.length();
        s[len].push_back(temp);
    }

    for (int len = 1; len <= 50; len++) {
        sort(s[len].begin(), s[len].end());
        auto last = unique(s[len].begin(), s[len].end());
        s[len].erase(last, s[len].end());
    }

    for (int i = 1; i <= 50; i++) {
        for (int j = 0; j < s[i].size(); j++) {
            cout << s[i][j] << endl;
        }
    }
}