#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int result = 0;

    getline(cin, s);

    bool minus_flag = false;
    size_t pos;
    int start = 0;

    while (!s.empty()) {
        int n = stoi(s, &pos);

        if (minus_flag) {
            result -= n;
        } else {
            result += n;
        }
        if (pos < s.size() && s[pos] == '-') {
            minus_flag = true;
        }
        if (pos < s.size())
            s.erase(0, pos + 1);
        else
            s.erase(0);
    }

    cout << result << '\n';
    return 0;
}