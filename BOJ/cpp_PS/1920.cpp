#include <algorithm>
#include <iostream>
#include <vector>
#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
using namespace std;

int main() {
    FASTIO;

    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    int m;
    cin >> m;
    string output;
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        output += (binary_search(A.begin(), A.end(), temp)) ? "1\n" : "0\n";
    }

    cout << output;
    return 0;
}