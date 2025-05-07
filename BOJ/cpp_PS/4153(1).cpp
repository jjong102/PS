#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int num[3];
    while (1) {
        for (int i = 0; i < 3; i++) {
            cin >> num[i];
        }
        sort(num, num + 3);
        if (num[0] == 0)
            return 0;
        cout << ((num[0] * num[0] + num[1] * num[1] == num[2] * num[2]) ? "right" : "wrong") << endl;
    }
}