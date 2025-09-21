#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
using ll = long long;

ll Padovan(int n) {
    if (n <= 5) {
        return n <= 3 ? 1 : 2;
    }

    vector<ll> pdv(n + 1);
    pdv[1] = 1;
    pdv[2] = 1;
    pdv[3] = 1;
    pdv[4] = 2;
    pdv[5] = 2;

    for (int i = 6; i <= n; i++) {
        pdv[i] = pdv[i - 1] + pdv[i - 5];
    }
    return pdv[n];
}

int main() {
    ostringstream out;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        out << Padovan(m) << '\n';
    }

    cout << out.str();

    return 0;
}