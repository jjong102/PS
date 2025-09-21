#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int vertex, edge;
    cin >> vertex >> edge;
    multimap<int, int> graph;
    vector<bool> visited(vertex + 1, false);
    visited[0] = true;

    queue<int> q;

    for (int i = 0; i < edge; i++) {
        int a, b;
        cin >> a >> b;
        graph.insert({a, b});
        graph.insert({b, a});
    }

    int start = 1;
    int cnt = 0;

    while (start < visited.size()) {
        if (!visited[start]) {
            q.push(start);
            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                if (!visited[curr]) {
                    visited[curr] = true;
                    auto range = graph.equal_range(curr);
                    for (auto it = range.first; it != range.second; ++it) {
                        if (!visited[it->second]) q.push(it->second);
                    }
                }
            }

            cnt++;
        }
        start = find(visited.begin(), visited.end(), false) - visited.begin();
    }

    cout << cnt << '\n';

    return 0;
}