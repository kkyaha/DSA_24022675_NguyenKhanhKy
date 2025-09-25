#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct QueueLL {
    Node* head;
    Node* tail;

    QueueLL() {
        head = tail = nullptr;
    }

    // O(1)
    void enqueue(int value) {
        Node* node = new Node{value, nullptr};
        if (tail == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    // O(1)
    void dequeue() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        if (head == nullptr) tail = nullptr;
        delete temp;
    }

    // O(1)
    int front() const {
        if (head == nullptr) cout<<"Queue empty";
        return head->data;
    }

    // O(1)
    bool empty() const { return head == nullptr; }
};

int main() {
    QueueLL qll;
    qll.enqueue(50);
    qll.enqueue(60);
    cout << "QueueLL front: " << qll.front() << endl;
    qll.dequeue();
    cout << "QueueLL front after dequeue: " << qll.front() << endl;
}
