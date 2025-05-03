#include <iostream>
// 1. 끝에 붙는 0은 10이 얼마나 곱해졌는지에 따라 결정된다.
// 2. 10 = 2*5인데 2가 더 많이 나옴. 따라서 5의 개수를 세면된다.

using namespace std;
int main() {
    int count = 0;
    int N;
    cin >> N;
    // 5는 5가 1개, 25는 5가 2개 125는 5가 3개 ...
    // 단순히 나누기 5한 몫으로는 이렇게 숨어있는 5를 잡을 수 없다.
    // 5를 곱해가면서 나눠준다.
    for (int i = 5; i <= N; i *= 5) {
        count += N / i;
    }

    cout << count << endl;
    return 0;
}
