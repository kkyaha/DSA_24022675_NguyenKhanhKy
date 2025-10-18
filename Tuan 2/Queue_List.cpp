#include <iostream>
using namespace std;

const int MAX = 100;

struct List {
    int data[MAX];
    int size;

    List() { size = 0; }

    // O(1)
    void insertTail(int value) {
        if (size >= MAX) return;
        data[size++] = value;
    }

    // O(n) vì phải dời phần tử
    void deleteHead() {
        if (size == 0) return;
        for (int i = 0; i < size - 1; i++)
            data[i] = data[i + 1];
        size--;
    }

    // O(1)
    int access(int i) const {
        if (i >= 0 && i < size) return data[i];
    }
};

struct Queue {
    List list;

    void enqueue(int value) { list.insertTail(value); } // O(1)
    void dequeue() { list.deleteHead(); }               // O(n)
    int front() const { return list.access(0); }        // O(1)
    bool empty() const { return list.size == 0; }       // O(1)
    int size() const { return list.size; }              // O(1)
};

int main() {
    Queue q;
    q.enqueue(5);
    q.enqueue(15);
    cout << "Queue front: " << q.front() << endl;
    q.dequeue();
    cout << "Queue front after dequeue: " << q.front() << endl;
}
