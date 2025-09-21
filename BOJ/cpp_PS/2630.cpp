// 만약, 수정한다면...
//  1. is_all_same이라는 함수 쓸 필요 없이 그냥 1의 개수를 세면 됨.
//      ex) 1의 개수가 N*N이면 그건 1로 꽉찬 색종이 인거고
//          1의 개수가 0이면 그건 0으로 꽉찬 색종이 인거고
//          둘다 아니면 그건 분할로 문제 해결 하면 된다!!
#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> graph;
bool is_all_same(int x, int y, int len) {
    for (int i = x; i < x + len; i++) {
        for (int j = y; j < y + len; j++) {
            if (graph[i][j] != graph[x][y]) return false;
        }
    }
    return true;
}

int count_0 = 0;
int count_1 = 0;
void count_color(int x, int y, int len) {
    if (is_all_same(x, y, len)) {
        if (graph[x][y] == 1) {
            count_1++;
        } else {
            count_0++;
        }
        return;
    }

    len = len / 2;
    count_color(x, y, len);
    count_color(x, y + len, len);
    count_color(x + len, y, len);
    count_color(x + len, y + len, len);
}

int main() {
    int n;
    cin >> n;
    graph = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    count_color(0, 0, n);
    cout << count_0 << '\n' << count_1 << '\n';

    return 0;
}