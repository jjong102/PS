#include <algorithm>
#include <iostream>
#include <vector>

#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
using namespace std;

struct coordinate {
    int x, y;
};

int main() {
    FASTIO;

    int n;
    cin >> n;
    vector<coordinate> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;
    }

    sort(v.begin(), v.end(), [](const coordinate &a, const coordinate &b) {
        if (a.x != b.x)
            return a.x < b.x;
        else
            return a.y < b.y;
    });

    for (int i = 0; i < n; i++) {
        cout << v[i].x << ' ' << v[i].y << '\n';
    }

    return 0;
}