#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, bool>> num(n);
    for (int j = 0; j < n; j++) {
        num[j] = {j + 1, true};
    }

    int i = k - 1;
    cout << "<";
    while (1) {
        if (count_if(num.begin(), num.end(),
                     [](const pair<int, bool>& p) { return p.second == true; }) == 1) {
            cout << num[i].first;
            break;
        }
        cout << num[i].first << ", ";
        num[i].second = false;

        int count = 0;
        while (count < k) {
            i = (i + 1) % n;
            if (num[i].second == true) {
                count++;
            }
        }
    }

    cout << ">" << endl;

    return 0;
}