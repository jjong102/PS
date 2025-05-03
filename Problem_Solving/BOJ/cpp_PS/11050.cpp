#include <iostream>
using namespace std;
int fac(int n) {
    int result = 1;
    for (int i = 1; i < n + 1; i++) {
        result *= i;
    }
    return result;
}
int main() {
    int n, k;
    cin >> n >> k;
    cout << fac(n) / (fac(n - k) * fac(k)) << endl;
}