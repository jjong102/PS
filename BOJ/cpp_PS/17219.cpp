#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

int main() {
    ostringstream out;
    int n, m;
    cin >> n >> m;

    unordered_map<string, string> find_password;
    for (int i = 0; i < n; i++) {
        string temp1, temp2;
        cin >> temp1 >> temp2;
        find_password.insert({temp1, temp2});
    }

    for (int i = 0; i < m; i++) {
        string temp;
        cin >> temp;
        out << find_password[temp] << '\n';
    }

    cout << out.str();
    return 0;
}