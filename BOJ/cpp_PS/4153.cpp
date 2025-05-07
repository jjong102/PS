#include <iostream>

using namespace std;

int main() {
    int num[3];
    while (1) {
        cin >> num[0] >> num[1] >> num[2];

        for (int i = 0; i < 2; i++) {
            if (num[i] > num[i + 1]) {
                int temp;
                temp = num[i];
                num[i] = num[i + 1];
                num[i + 1] = temp;
            }
        }
        if (num[0] == 0 && num[1] == 0 && num[2] == 0) {
            return 0;
        } else if (num[0] * num[0] + num[1] * num[1] == num[2] * num[2]) {
            cout << "right" << endl;
        } else {
            cout << "wrong" << endl;
        }
    }
}