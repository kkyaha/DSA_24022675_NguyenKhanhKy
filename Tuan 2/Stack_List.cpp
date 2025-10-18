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

    // O(1)
    void deleteTail() {
        if (size == 0) return;
        size--;
    }

    // O(1)
    int access(int i) const {
        if (i >= 0 && i < size) return data[i];
    }
};

struct Stack {
    List list;

    // O(1)
    void push(int value) {
        list.insertTail(value);
    }

    // O(1)
    void pop() {
        list.deleteTail();
    }

    // O(1)
    int top() const {
        if (list.size == 0) cout<<"Stack empty";
        return list.access(list.size - 1);
    }

    bool empty() const { return list.size == 0; } // O(1)
    int size() const { return list.size; }        // O(1)
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    cout << "Stack top: " << s.top() << endl;
    s.pop();
    cout << "Stack top after pop: " << s.top() << endl;
}
