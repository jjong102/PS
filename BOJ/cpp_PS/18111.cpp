// <처음 내가 접근했던 방식>
// 1. 일단 다 파버리고 (= 최대시간)
// 2. 그 다음 매꾸는 전략
//      원래 인벤토리에 있던 것들은 -1 해주고
//      내가 임의로 파버린 블록은 -2 해준다.
//
// 수학적으로는 가능.
// 구현 상당히 어렵고, 디버깅도 쉽지 않음.
//
// 그냥 밑에 와 같이 모든 높이 비교하는 것으로 풀자!

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, B;
    cin >> N >> M >> B;

    vector<vector<int>> land(N, vector<int>(M));
    int minH = 256, maxH = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> land[i][j];
            minH = min(minH, land[i][j]);
            maxH = max(maxH, land[i][j]);
        }
    }

    int answer_time = 1e9;
    int answer_height = 0;

    // 모든 높이 시도
    for (int h = minH; h <= maxH; h++) {
        int time = 0;
        int block = B;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int diff = land[i][j] - h;
                if (diff > 0) {
                    time += diff * 2;
                    block += diff;
                } else if (diff < 0) {
                    time += -diff;
                    block -= -diff;
                }
            }
        }

        if (block >= 0) {
            if (time <= answer_time) {
                answer_time = time;
                answer_height = h;
            }
        }
    }

    cout << answer_time << " " << answer_height << "\n";
    return 0;
}