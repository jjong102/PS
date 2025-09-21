#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
vector<int> Heap;
int erase_MinHeap() {
    if (Heap.size() <= 1) return 0;

    int result = Heap[1];
    int last = Heap.back();
    Heap.pop_back();

    int find_index = 1;
    int child_index;

    while (find_index * 2 < Heap.size()) {
        int left = find_index * 2;
        int right = find_index * 2 + 1;

        // 오른쪽 자식이 없는 경우는 빼자.
        if (right < Heap.size() && Heap[right] < Heap[left]) {
            child_index = right;
        } else {
            child_index = left;
        }

        if (last <= Heap[child_index]) break;

        Heap[find_index] = Heap[child_index];
        find_index = child_index;
    }

    Heap[find_index] = last;
    return result;
}

void insert_MinHeap(int x) {
    Heap.push_back(0);
    int find_index = Heap.size() - 1;

    while (find_index > 1 && x < Heap[find_index / 2]) {
        int parent_index = find_index / 2;
        Heap[find_index] = Heap[parent_index];
        find_index = parent_index;
    }

    Heap[find_index] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ostringstream out;
    int n;
    cin >> n;
    Heap.push_back(0);
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp == 0) {
            out << erase_MinHeap() << '\n';
        } else {
            insert_MinHeap(temp);
        }
    }

    cout << out.str();
    return 0;
}