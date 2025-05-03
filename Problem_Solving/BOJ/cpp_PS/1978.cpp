#include <iostream>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases;
    cin >> cases;
    int num[cases];
    int count = 0;

    for (int i = 0; i < cases; i++) {
        cin >> num[i];
        count++;
        if (num[i] == 1) {
            count--;
        }
        for (int j = 2; j < num[i]; j++) {
            if (num[i] % j == 0) {
                count--;
                break;
            }
        }
    }

    cout << count << endl;
}