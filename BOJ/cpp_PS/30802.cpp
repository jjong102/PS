#include <iostream>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p, t, T_print = 0;
    int T[6];

    cin >> n;
    for (int i = 0; i < 6; i++) {
        cin >> T[i];
    }
    cin >> t >> p;
    for (int i = 0; i < 6; i++) {
        if (T[i] % t == 0) {
            T_print += T[i] / t;
            continue;
        }
        T_print += T[i] / t + 1;
    }

    cout << T_print << endl
         << n / p << ' ' << n % p << endl;
}