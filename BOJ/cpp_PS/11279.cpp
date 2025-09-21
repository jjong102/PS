#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class MaxHeap {
   private:
    vector<int> Heap;

    int bigger_child(int index) {
        int left = index * 2;
        int right = index * 2 + 1;
        if (left >= Heap.size()) return -1;
        if (right >= Heap.size()) return left;
        return (Heap[right] > Heap[left]) ? right : left;
    }

   public:
    MaxHeap() {
        Heap.push_back(-1);  // index 0은 더미
    }

    void add(int x) {
        Heap.push_back(x);
        int index = Heap.size() - 1;

        while (index > 1 && x > Heap[index / 2]) {
            Heap[index] = Heap[index / 2];
            index /= 2;
        }
        Heap[index] = x;
    }

    int remove() {
        if (Heap.size() <= 1) return -1;

        int result = Heap[1];
        int last = Heap.back();
        Heap.pop_back();

        int index = 1;
        int child;
        while ((child = bigger_child(index)) != -1 && last < Heap[child]) {
            Heap[index] = Heap[child];
            index = child;
        }
        Heap[index] = last;
        return result;
    }
};

int main() {
    ostringstream out;
    int n;
    cin >> n;
    MaxHeap heap;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp == 0) {
            int result = heap.remove();
            if (result == -1) {
                out << 0 << '\n';
                continue;
            }
            out << result << '\n';
            continue;
        }
        heap.add(temp);
    }

    cout << out.str();
    return 0;
}