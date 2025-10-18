#include <bits/stdc++.h>

using namespace std;

template <int Capacity>
struct MaxBinaryHeap {
private:
    int pq[Capacity];
    int currentSize;

    void swim(int k) {
        while (k > 0 && pq[(k - 1) / 2] < pq[k]) {
            swap(pq[(k - 1) / 2], pq[k]);
            k = (k - 1) / 2;
        }
    }

    void sink(int k) {
        while (2 * k + 1 < currentSize) {
            int j = 2 * k + 1;
            if (j + 1 < currentSize && pq[j] < pq[j + 1]) {
                j++;
            }
            if (!(pq[k] < pq[j])) {
                break;
            }
            swap(pq[k], pq[j]);
            k = j;
        }
    }

public:
    MaxBinaryHeap() {
        currentSize = 0;
    }

    // Độ phức tạp: O(1)
    bool isEmpty() const {
        return currentSize == 0;
    }

    // Độ phức tạp: O(1)
    int size() const {
        return currentSize;
    }

    // Độ phức tạp: O(log N)
    void insert(int value) {
        if (currentSize == Capacity) { // Dùng Capacity từ template
            return;
        }
        pq[currentSize] = value;
        swim(currentSize);
        currentSize++;
    }

    // Độ phức tạp: O(1)
    int max() const {
        if (isEmpty()) {
            return INT_MIN;
        }
        return pq[0];
    }

    // Độ phức tạp: O(log N)
    int delMax() {
        if (isEmpty()) {
            return INT_MIN;
        }
        int maxValue = pq[0];
        swap(pq[0], pq[currentSize - 1]);
        currentSize--;
        sink(0);
        return maxValue;
    }
};


template <int Capacity>
struct PriorityQueue {
private:
    MaxBinaryHeap<Capacity> heap;

public:
    void insert(int value) {
        heap.insert(value);
    }

    int delMax() {
        return heap.delMax();
    }

    bool isEmpty() const {
        return heap.isEmpty();
    }

    int max() const {
        return heap.max();
    }

    int size() const {
        return heap.size();
    }
};


int main() {
    PriorityQueue<5> pq;

    pq.insert(15);
    pq.insert(30);
    pq.insert(10);
    pq.insert(50);
    pq.insert(25);

    cout << "Kich thuoc hien tai: " << pq.size() << endl;
    cout << "\nThu chen them phan tu 100 vao hang doi da day:" << endl;
    pq.insert(100);
    cout << "Kich thuoc sau khi chen: " << pq.size() << endl;

    cout << "\nXoa cac phan tu:" << endl;
    while (!pq.isEmpty()) {
        cout << "Lay ra: " << pq.delMax() << endl;
    }
    cout << "\nThu lay phan tu tu hang doi rong:" << endl;
    pq.delMax();

    return 0;
}
