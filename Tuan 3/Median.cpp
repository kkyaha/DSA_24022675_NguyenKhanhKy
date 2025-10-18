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
        if (currentSize == Capacity) { 
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
struct MinBinaryHeap {
private:
    MaxBinaryHeap<Capacity> maxHeap;

public:
    bool isEmpty() const {
        return maxHeap.isEmpty();
    }

    int size() const {
        return maxHeap.size();
    }

    void insert(int value) {
        maxHeap.insert(-value);
    }

    int min() const {
        return -maxHeap.max();
    }

    int delMin() {
        return -maxHeap.delMax();
    }
};

void runningMedian(const vector<int>& arr) {
	
    const int MAX_ELEMENTS = 100;

    // Nửa nhỏ hơn
    MaxBinaryHeap<MAX_ELEMENTS> left_heap; 
    
    // Nửa lớn hơn
    MinBinaryHeap<MAX_ELEMENTS> right_heap; 

    cout << fixed << setprecision(1);

    for (int num : arr) {
        left_heap.insert(num);

        right_heap.insert(left_heap.delMax());

        if (left_heap.size() < right_heap.size()) {
            left_heap.insert(right_heap.delMin());
        }
ị
        double median;
        if (left_heap.size() > right_heap.size()) {
            median = left_heap.max();
        } else {
            median = (left_heap.max() + right_heap.min()) / 2.0;
        }
        
        cout << median << endl;
    }
}

int main() {
    vector<int> inputStream = {12, 4, 5, 3, 8, 7};
    
    cout << "Trung vi cap nhat sau moi so:" << endl;
    runningMedian(inputStream);

    return 0;
}