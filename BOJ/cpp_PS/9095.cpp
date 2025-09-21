#include <iostream>
#include <sstream>

using namespace std;
int make_num_count(int n) {
    int make_num[n + 1];

    make_num[1] = 1;
    make_num[2] = 2;
    make_num[3] = 4;

    for (int i = 4; i <= n; i++) {
        make_num[i] = make_num[i - 1] + make_num[i - 2] + make_num[i - 3];
    }

    return make_num[n];
}

int main() {
    ostringstream out;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        out << make_num_count(num) << '\n';
    }

    cout << out.str();
    return 0;
}