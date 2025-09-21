#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
using ll = long long;
int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<ll> sorted = v;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    for (int i = 0; i < n; i++) {
        cout << lower_bound(sorted.begin(), sorted.end(), v[i]) - sorted.begin() << ' ';
    }

    return 0;
}