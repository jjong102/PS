#include <iostream>
#include <sstream>
using namespace std;

int count_0[41];
int count_1[41];

void init() {
    count_0[0] = 1;
    count_1[0] = 0;
    count_0[1] = 0;
    count_1[1] = 1;
    for (int i = 2; i <= 40; i++) {
        count_0[i] = count_0[i - 1] + count_0[i - 2];
        count_1[i] = count_1[i - 1] + count_1[i - 2];
    }
}

int main() {
    ostringstream out;
    init();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        out << count_0[num] << " " << count_1[num] << '\n';
    }

    cout << out.str();
    return 0;
}