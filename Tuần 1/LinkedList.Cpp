#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct LinkedList {
    Node* head;

    // Constructor (thay cho init)
    LinkedList() {
        head = nullptr;
    }

    // Tạo node mới
    Node* createNode(int value) {
        Node* node = new Node;
        node->data = value;
        node->next = nullptr;
        return node;
    }

    // Truy cập phần tử tại vị trí i
    int access(int i) const {
        Node* current = head;
        int index = 0;
        while (current != nullptr) {
            if (index == i) return current->data;
            current = current->next;
            index++;
        }
    }

    // Chèn phần tử vào đầu
    void insertHead(int value) {
        Node* node = createNode(value);
        node->next = head;
        head = node;
    }

    // Chèn phần tử vào cuối
    void insertTail(int value) {
        Node* node = createNode(value);
        if (head == nullptr) {
            head = node;
            return;
        }
        Node* current = head;
        while (current->next != nullptr)
            current = current->next;
        current->next = node;
    }

    // Chèn vào vị trí i
    void insertAt(int i, int value) {
        if (i == 0) {
            insertHead(value);
            return;
        }
        Node* current = head;
        int index = 0;
        while (current != nullptr && index < i - 1) {
            current = current->next;
            index++;
        }
        if (current == nullptr) return;
        Node* node = createNode(value);
        node->next = current->next;
        current->next = node;
    }

    // Xóa phần tử đầu
    void deleteHead() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Xóa phần tử cuối
    void deleteTail() {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* current = head;
        while (current->next->next != nullptr)
            current = current->next;
        delete current->next;
        current->next = nullptr;
    }

    // Xóa tại vị trí i
    void deleteAt(int i) {
        if (i == 0) {
            deleteHead();
            return;
        }
        Node* current = head;
        int index = 0;
        while (current != nullptr && index < i - 1) {
            current = current->next;
            index++;
        }
        if (current == nullptr || current->next == nullptr) return;
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    // Duyệt xuôi
    void traverseForward() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Duyệt ngược (đệ quy)
    void traverseBackwardHelper(Node* node) const {
        if (node == nullptr) return;
        traverseBackwardHelper(node->next);
        cout << node->data << " ";
    }

    void traverseBackward() const {
        traverseBackwardHelper(head);
        cout << endl;
    }
};

int main() {
    LinkedList myList;

    myList.insertTail(10);
    myList.insertTail(20);
    myList.insertHead(5);
    myList.insertAt(1, 15);

    cout << "Duyệt xuôi: ";
    myList.traverseForward();

    cout << "Duyệt ngược: ";
    myList.traverseBackward();

    myList.deleteHead();
    myList.deleteTail();
    myList.deleteAt(0);

    cout << "Sau khi xóa: ";
    myList.traverseForward();

    cout << "Truy cập phần tử thứ 0: " << myList.access(0) << endl;

    return 0;
}
