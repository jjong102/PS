#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    queue<int> que;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "push") {
            int temp;
            cin >> temp;
            que.push(temp);
        } else if (s == "pop") {
            if (que.empty()) {
                cout << -1 << endl;
            } else {
                cout << que.front() << endl;
                que.pop();
            }
        } else if (s == "size") {
            cout << que.size() << endl;
        } else if (s == "empty") {
            if (que.empty()) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else if (s == "front") {
            if (que.empty()) {
                cout << -1 << endl;
            } else {
                cout << que.front() << endl;
            }
        } else if (s == "back") {
            if (que.empty()) {
                cout << -1 << endl;
            } else {
                cout << que.back() << endl;
            }
        }
    }
    return 0;
}