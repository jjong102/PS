#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    int end = 1;
    cin >> num;
    for (int distance = 1; distance <= num; distance++) {
        end += 6 * (distance - 1);
        if (end >= num) {
            cout << distance << endl;
            return 0;
        }
    }
}