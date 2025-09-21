// 시간이 중요한 경우에는
// 재귀기반 dfs보다 queue기반 bfs가 효과적

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct xy {
    int y, x;
};

int col, row;
int cnt = 0;
vector<vector<char>> map;
vector<vector<bool>> visited;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void bfs(xy start) {
    queue<xy> q;
    q.push(start);
    visited[start.y][start.x] = true;

    while (!q.empty()) {
        xy point = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = point.y + dy[i];
            int nx = point.x + dx[i];

            if (ny < 0 || ny >= col || nx < 0 || nx >= row) continue;
            if (visited[ny][nx]) continue;
            if (map[ny][nx] == 'X') continue;

            visited[ny][nx] = true;
            if (map[ny][nx] == 'P') cnt++;
            q.push({ny, nx});
        }
    }
}

int main() {
    cin >> col >> row;
    xy start;
    map = vector<vector<char>>(col, vector<char>(row));
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'I') start = {i, j};
        }
    }
    visited = vector<vector<bool>>(col, vector<bool>(row, false));

    bfs(start);

    if (cnt == 0)
        cout << "TT" << '\n';
    else
        cout << cnt << '\n';
    return 0;
}