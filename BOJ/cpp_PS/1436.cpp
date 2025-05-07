#include <iostream>
#include <string>
using namespace std;
int main() {
    int N;
    int count = 0;
    cin >> N;
    for (int i = 666;; i++) {
        if (to_string(i).find("666") != string::npos) {
            count++;
            if (count == N) {
                cout << i << endl;
                return 0;
            }
        }
    }
}