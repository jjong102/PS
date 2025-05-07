#include <iostream>
#include <string>
using namespace std;

int main() {
    int case_;
    int n;
    string s;
    cin >> case_;
    cin.ignore();
    for (int i = 0; i < case_; i++) {
        cin >> n >> s;
        for (int j = 0; j < s.length(); j++) {
            for (int k = 0; k < n; k++) {
                cout << s[j];
            }
        }
        cout << endl;
    }
}