// bitset<21> toggle로 바꾸어 사용하면 더 빠름

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
int main() {
    ostringstream out;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<bool> toggle(20, false);
    for (int i = 0; i < n; i++) {
        string string_temp;
        int num_temp;
        cin >> string_temp;
        if (string_temp == "add") {
            cin >> num_temp;
            toggle[num_temp - 1] = true;
        } else if (string_temp == "remove") {
            cin >> num_temp;
            toggle[num_temp - 1] = false;
        } else if (string_temp == "check") {
            cin >> num_temp;
            out << (toggle[num_temp - 1] ? 1 : 0) << '\n';
        } else if (string_temp == "toggle") {
            cin >> num_temp;
            if (toggle[num_temp - 1])
                toggle[num_temp - 1] = false;
            else
                toggle[num_temp - 1] = true;
        } else if (string_temp == "all") {
            for (int i = 0; i < 20; i++) {
                toggle[i] = true;
            }
        } else if (string_temp == "empty") {
            for (int i = 0; i < 20; i++) {
                toggle[i] = false;
            }
        }
    }
    cout << out.str();
    return 0;
}