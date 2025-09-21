// 이거 우선 순위큐로 풀면 쉽게 풀수 있어요잉

#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;
using dii = deque<pair<int, int>>;

dii make_doc(int n) {
    dii result;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        result.push_back({i, temp});  // 처음 순서, 중요도 들어감.
    }
    return result;
}

int imp_jdg(int find, dii dq) {
    int count = 0;
    while (!dq.empty()) {
        // 일단 최대 값을 찾아유
        auto max = max_element(
            dq.begin(), dq.end(),
            [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; });

        // 처음 중요도랑 최대 값이랑 같으면, count++
        if (dq.front().second == (*max).second) {
            count++;
            // 처음 중요도가 최대값이랑 같은데 그게 찾는 값이다?? 바로 출력이여유
            if (dq.front().first == find) {
                return count;
            }
            dq.pop_front();
            // 다르면 일단 뒤로 보내버려유유,
        } else {
            pair<int, int> temp = dq.front();
            dq.pop_front();
            dq.push_back(temp);
        }
    }
}

int main() {
    int n;
    cin >> n;

    dii doc;

    for (int i = 0; i < n; i++) {
        int doc_num;
        int first_place;
        cin >> doc_num >> first_place;

        doc = make_doc(doc_num);

        cout << imp_jdg(first_place, doc) << endl;
    }

    return 0;
}