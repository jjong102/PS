#include <iostream>

using namespace std;

int main() {
    int weight;
    cin >> weight;
    int index = weight / 5;

    int remain;
    for (int i = index; i >= 0; i--) {
        if ((weight - (5 * i)) % 3 == 0) {
            remain = weight - (5 * i);
            cout << (remain / 3 + (weight - remain) / 5) << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}