#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>


using namespace std;
using vdb = vector<double>;
#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

int main() {
    FASTIO;
    int num = 0;
    double m;
    double result = 0;
    vdb score;
    cin >> num;
    for (int i = 0; i < num; i++) {
        double temp = 0;
        cin >> temp;
        score.push_back(temp);
    }
    m = *max_element(score.begin(), score.end());

    for (int j = 0; j < num; j++) {
        result += score[j] / m * 100;
    }

    cout << fixed << setprecision(15) << result / num << endl;
    return 0;
}