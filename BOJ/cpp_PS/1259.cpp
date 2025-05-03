#include <iostream>
#include <string>
#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
using namespace std;

int main() {
    FASTIO;
    string num_s;
    while (1) {
        bool flage = true;
        cin >> num_s;
        if (num_s[0] == '0') {
            return 0;
        }

        int n = num_s.size();
        int std = n / 2;
        int num[n];
        for (int i = 0; i < n; i++) {
            num[i] = num_s[i] - '0';
        }

        if (n % 2 != 0) {
            for (int i = 1; i < std + 1; i++) {
                if (num[std - i] != num[std + i]) {
                    flage = false;
                    break;
                }
            }
        } else if (n % 2 == 0 && num[std] != num[std - 1]) {
            flage = false;
        } else if (n % 2 == 0 && num[std] == num[std - 1]) {
            if (std == 1) {
                flage = true;
            } else {
                for (int i = 1; i < std; i++) {
                    if (num[std - 1 - i] != num[std + i]) {
                        flage = false;
                        break;
                    }
                }
            }
        }

        if (flage) {
            cout << "yes" << endl;
        }

        else {
            cout << "no" << endl;
        }
    }
}
