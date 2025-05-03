#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, num_count;
    int result;
    int set = 0;

    vector<int> num;
    cin >> num_count >> M;
    for (int i = 0; i < num_count; i++) {
        int temp;
        cin >> temp;
        num.push_back(temp);
    }

    for (int i = 0; i < num_count - 2; i++) {
        for (int k = i + 1; k < num_count - 1; k++) {
            for (int j = k + 1; j < num_count; j++) {
                result = num[i] + num[k] + num[j];
                if (result <= M && set < result)
                    set = result;
            }
        }
    }

    cout << set << endl;
    return 0;
}