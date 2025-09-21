#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n, link;
    cin >> n >> link;

    vector<bool> visited(n + 1, false);

    unordered_multimap<int, int> linked;
    for (int i = 0; i < link; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        linked.insert({temp1, temp2});
        linked.insert({temp2, temp1});
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        auto range = linked.equal_range(curr);
        for (auto it = range.first; it != range.second; ++it) {
            int next = it->second;
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    cout << count(visited.begin(), visited.end(), true) - 1 << '\n';

    return 0;
}