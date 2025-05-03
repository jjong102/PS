#include <iostream>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    int constructor = 0;
    cin >> num;
    for (int i = 0; i < 1000000; i++) {
        int temp = i;
        for (int digit = 100000; digit >= 1; digit = digit / 10) {
            int digit_num;
            digit_num = temp / digit;
            if (digit_num == 0) {
                continue;
            } else if (digit == 1) {
                constructor += temp;
            } else {
                constructor += digit_num;
                temp -= digit_num * digit;
            }
        }
        constructor += i;
        if (constructor == num) {
            cout << i << endl;
            return 0;
        } else {
            constructor = 0;
        }
    }
    cout << 0 << endl;
}