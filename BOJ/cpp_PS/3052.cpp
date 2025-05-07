#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    for (int i = 0; i < 10; i++) {
        int scale;
        cin >> scale;
        s.insert(scale % 42);
    }

    cout << s.size();
}