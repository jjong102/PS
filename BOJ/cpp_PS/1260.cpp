#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

void dfs(int start, const vector<vector<int>>& graph, vector<bool>& visited) {
    stack<int> stk;
    stk.push(start);

    while (!stk.empty()) {
        int curr = stk.top();
        stk.pop();

        if (visited[curr]) continue;
        visited[curr] = true;
        cout << curr << ' ';

        // 오름차순 방문을 위해 reverse된 순서로 스택에 push
        for (auto it = graph[curr].rbegin(); it != graph[curr].rend(); ++it) {
            int next = *it;
            if (!visited[next]) {
                stk.push(next);
            }
        }
    }
}

void bfs(int start, const vector<vector<int>>& graph, vector<bool>& visited) {
    queue<int> que;
    que.push(start);
    visited[start] = true;

    while (!que.empty()) {
        int curr = que.front();
        que.pop();
        cout << curr << ' ';

        for (int next : graph[curr]) {
            if (!visited[next]) {
                visited[next] = true;
                que.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, V;
    cin >> N >> M >> V;

    vector<vector<int>> graph(N + 1);
    vector<bool> visited(N + 1, false);

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(V, graph, visited);
    fill(visited.begin(), visited.end(), false);
    cout << '\n';
    bfs(V, graph, visited);

    return 0;
}