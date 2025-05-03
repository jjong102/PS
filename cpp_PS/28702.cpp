#include <iostream>
#include <string>
#include <vector>

using namespace std;
using vs = vector<string>;
using vi = vector<int>;

int main() {
    vs s;
    vi si;
    int result = 0;
    for (int i = 0; i < 3; i++) {
        string temp;
        cin >> temp;
        s.push_back(temp);
        try {
            result = stoi(s[i]) - i + 3;
        } catch (...) {
            continue;
        }
    }

    if (result % 3 == 0 && result % 5 == 0) {
        cout << "FizzBuzz" << endl;
    } else if (result % 3 == 0 && result % 5 != 0) {
        cout << "Fizz" << endl;
    } else if (result % 3 != 0 && result % 5 == 0) {
        cout << "Buzz" << endl;
    } else {
        cout << result << endl;
    }
}