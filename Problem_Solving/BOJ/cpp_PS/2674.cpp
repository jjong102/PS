#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
int main() {
    int t;
    cin >> t;
    char arr[t][30];
    int n[t];
    cin.ignore(); // '\n'무시해줘야함.
    for (int i = 0; i < t; i++) {
        string s;
        getline(cin, s);
        istringstream iss(s);
        string s1;
        iss >> n[i] >> s1;
        strcpy(arr[i], s1.c_str());
    }

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < strlen(arr[i]); j++) {
            for (int k = 0; k < n[i]; k++) {
                cout << arr[i][j];
            }
        }
        cout << endl;
    }
}