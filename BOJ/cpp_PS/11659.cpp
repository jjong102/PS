// 만약, 수정한다면...
//  1. perfix 배열은 index==1에서 시작하자, 그래야 불필요한 조건문 안써도 됨.
//  2. 1번하면, if (start == 1) 출력하고 continue; 이런거 안써도됨.

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ostringstream out;
    int n, m;
    cin >> n >> m;
    vector<int> num_sum(n);

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (i == 0) {
            num_sum[0] = num;
            continue;
        }
        num_sum[i] = num_sum[i - 1] + num;
    }

    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        if (start == 1) {
            out << num_sum[end - 1] << '\n';
            continue;
        }
        out << (num_sum[end - 1] - num_sum[start - 2]) << '\n';
    }

    cout << out.str();
    return 0;
}