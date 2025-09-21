#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int row, col;

vector<vector<int>> field;
vector<vector<bool>> visited;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[y][x] = true;

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            // 행의 최대 범위는 열의 개수임.
            // 열의 최대 범위는 행의 개수임.

            if (nx < 0 || ny < 0 || nx >= col || ny >= row) continue;
            if (field[ny][nx] == 1 && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> col >> row >> n;

        field = vector<vector<int>>(row, vector<int>(col, 0));
        visited = vector<vector<bool>>(row, vector<bool>(col, false));

        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            field[y][x] = 1;
        }

        int count = 0;
        for (int y = 0; y < row; y++) {
            for (int x = 0; x < col; x++) {
                if (field[y][x] == 1 && !visited[y][x]) {
                    bfs(x, y);
                    count++;
                }
            }
        }

        cout << count << '\n';
    }
    return 0;
}