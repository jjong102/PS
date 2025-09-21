#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ostringstream out;

    int n, m;
    cin >> n >> m;
    set<string> s1;
    set<string> s2;

    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        s1.insert(temp);
    }

    for (int i = 0; i < m; i++) {
        string temp;
        cin >> temp;
        s2.insert(temp);
    }

    vector<string> result;
    int out_count = 0;
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(result));
    for (string s : result) {
        out << s << '\n';
        out_count++;
    }
    cout << out_count << '\n' << out.str();
    return 0;
}