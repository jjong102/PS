#include <algorithm>
#include <iostream>

using namespace std;

int p_num(int f, int n) {
    int num[15][15];
    fill(&num[0][0], &num[0][0] + 15 * 15, 0);
    for (int j = 1; j < 15; j++) {
        num[0][j] = j;  // 0층 초기 값 설정.
    }
    // 14*14의 아파트 사람 수 만들기
    for (int h = 1; h < 15; h++) {  // 1층 1호부터 값 설정.
        for (int r = 1; r < 15; r++) {
            int temp = 0;
            for (int r_t = r; r_t >= 1; r_t--) {
                temp += num[h - 1][r_t];
            }
            num[h][r] = temp;
        }
    }
    return num[f][n];
}

int main() {
    int f;
    int n;
    int t;

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> f >> n;
        cout << p_num(f, n) << endl;
    }
    return 0;
}