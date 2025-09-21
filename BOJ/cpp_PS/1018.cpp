// for문 작성할때 잔실수가 너무 많아요.
// for문에서 실수하면 디버깅 하기가 너무 어렵습니다.
// 집중해서 잘 하세요잉!!!

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int repaint(const vector<string> &s, int M, int N) {
    int result = 1e9;
    string optimal[2] = {"WBWBWBWB", "BWBWBWBW"};
    for (int i = 0; i <= M - 8; i++) {
        for (int j = 0; j <= N - 8; j++) {
            int count_1 = 0;
            int count_2 = 0;
            for (int h = i; h < i + 8; h++) {
                for (int w = j; w < j + 8; w++) {
                    if (optimal[(h - i) % 2][w - j] != s[h][w]) {
                        count_1++;
                    }
                    if (optimal[(h - i + 1) % 2][w - j] != s[h][w]) {
                        count_2++;
                    }
                }
            }
            result = min(result, min(count_1, count_2));
        }
    }
    return result;
}

int main() {
    int M, N;
    cin >> M >> N;
    vector<string> board(M);

    for (int i = 0; i < M; i++) {
        cin >> board[i];
    }
    cout << repaint(board, M, N) << endl;

    return 0;
}