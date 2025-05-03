#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

string removeSpaces(string input) {
    input.erase(remove(input.begin(), input.end(), ' '), input.end());
    return input;
}

int main() {
    string scale_r;
    getline(cin, scale_r);
    string scale = removeSpaces(scale_r);
    for (int i = 0; i < 7; i++) {
        int scale_1 = scale[i] - '0';
        int scale_2 = scale[i + 1] - '0';
        int growth_rate = scale_2 - scale_1;
        growth_rate = abs(growth_rate);
        if (growth_rate != 1) {
            cout << "mixed" << endl;
            return 0;
        }
    }

    if (scale[0] - '0' == 1) {
        cout << "ascending" << endl;
    } else {
        cout << "descending" << endl;
    }
}