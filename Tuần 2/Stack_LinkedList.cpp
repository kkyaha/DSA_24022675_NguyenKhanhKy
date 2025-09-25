#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct LinkedList {
    Node* head;
    LinkedList() { head = nullptr; }

    // O(1)
    void insertHead(int value) {
        Node* node = new Node{value, head};
        head = node;
    }

    // O(1)
    void deleteHead() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // O(1)
    int front() const {
        if (head == nullptr) cout<<"Empty list";
        return head->data;
    }

    // O(1)
    bool empty() const { return head == nullptr; }
};

struct StackLL {
    LinkedList list;

    void push(int value) { list.insertHead(value); } // O(1)
    void pop() { list.deleteHead(); }                // O(1)
    int top() const { return list.front(); }         // O(1)
    bool empty() const { return list.empty(); }      // O(1)
};

int main() {
    StackLL sll;
    sll.push(100);
    sll.push(200);
    cout << "StackLL top: " << sll.top() << endl;
    sll.pop();
    cout << "StackLL top after pop: " << sll.top() << endl;
}
