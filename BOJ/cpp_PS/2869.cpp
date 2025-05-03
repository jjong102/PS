#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ll d = 0;
    ll n = 0;
    ll h = 0;
    ll p = 0;
    ll day = 0;
    ll remain = 0;
    cin >> d >> n >> h;
    p = d - n;
    remain = h - d;
    if (h <= d) {
        cout << 1 << endl;
        return 0;
    }
    if (n >= d) {
        return 0;
    }
    day = (remain + p - 1) / p + 1;
    cout << day << endl;
    return 0;
}
