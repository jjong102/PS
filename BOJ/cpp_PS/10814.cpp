#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
struct member {
    int old;
    int index;
    string name;
};

int main() {
    int n;
    cin >> n;
    vector<member> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].old >> v[i].name;
        v[i].index = i;
    }
    sort(v.begin(), v.end(), [](const member &a, const member &b) {
        if (a.old != b.old)
            return a.old < b.old;  // 나이 오름 차순으로 정렬
        else
            return a.index < b.index;  // 인덱스 오름 차순으로 정렬
    });

    for (member i : v) {
        cout << i.old << ' ' << i.name << endl;
    }

    return 0;
}