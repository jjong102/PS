#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
// for문 할때 j를 i로 오타 냈는지 확인하세요!
using namespace std;
constexpr int INF = 1e9;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) {
        graph[i][i] = 0;
    }

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;  // 친구 양뱡향임 주의!
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    map<int, vector<int>> result;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum += graph[i][j];
        }
        // map 안쓰고 여기서 min_sum과 answer = i 구해서 출력도 가능함.
        result[sum].push_back(i);
        sum = 0;
    }

    auto it = result.begin();
    int index = it->first;
    cout << *min_element(result[index].begin(), result[index].end());

    return 0;
}