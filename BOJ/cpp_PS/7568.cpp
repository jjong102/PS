#include <iostream>
#include <vector>

using namespace std;

struct Triple {
    int weight, height, rank;
};

using vT = vector<Triple>;

int main() {
    int case_;
    cin >> case_;
    vT v;
    for (int i = 0; i < case_; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        v.push_back({temp1, temp2, 1});
    }
    for (int i = 0; i < case_; i++) {
        for (int j = 0; j < case_; j++) {
            if (i == j) {
                continue;
            }
            if (v[i].weight > v[j].weight && v[i].height > v[j].height) {
                v[j].rank++;
            }
        }
    }

    for (int i = 0; i < case_; i++) {
        cout << v[i].rank << ' ';
    }

    return 0;
}