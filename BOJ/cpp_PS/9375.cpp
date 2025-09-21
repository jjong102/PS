// 만약, 수정한다면..
//  1. 굳이 옷의 이름 까지 저장 할 필요 없음.
//  2. nuordered_map<string, int>형으로 저장해서 뒤에 int값을 올려주면됨.

#include <iostream>
#include <set>
#include <sstream>
#include <unordered_map>

using namespace std;

int main() {
    ostringstream out;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;

        unordered_multimap<string, string> clothes;
        for (int j = 0; j < m; j++) {
            string temp1, temp2;
            cin >> temp1 >> temp2;
            clothes.insert({temp2, temp1});
        }

        set<string> key_num;
        for (const auto& [key, value] : clothes) {
            key_num.insert(key);
        }

        int result = 1;
        for (const auto& key : key_num) {
            result *= clothes.count(key) + 1;  // 안입는 경우의 수 포함.
        }

        out << result - 1 << '\n';  // 알몸인 경우의 수 뺌.
    }

    cout << out.str();
    return 0;
}