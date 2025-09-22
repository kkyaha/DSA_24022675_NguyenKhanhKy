#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct LinkedList {
    Node* head;
};

// Khởi tạo danh sách
void init(LinkedList &list) {
    list.head = nullptr;
}

// Tạo node mới
Node* createNode(int value) {
    Node* node = new Node;
    node->data = value;
    node->next = nullptr;
    return node;
}

// Truy cập phần tử tại vị trí i
int access(const LinkedList &list, int i) {
    Node* current = list.head;
    int index = 0;
    while (current != nullptr) {
        if (index == i) return current->data;
        current = current->next;
        index++;
    }
}

// Chèn phần tử vào đầu
void insertHead(LinkedList &list, int value) {
    Node* node = createNode(value);
    node->next = list.head;
    list.head = node;
}

// Chèn phần tử vào cuối
void insertTail(LinkedList &list, int value) {
    Node* node = createNode(value);
    if (list.head == nullptr) {
        list.head = node;
        return;
    }
    Node* current = list.head;
    while (current->next != nullptr)
        current = current->next;
    current->next = node;
}

// Chèn vào vị trí i
void insertAt(LinkedList &list, int i, int value) {
    if (i == 0) {
        insertHead(list, value);
        return;
    }
    Node* current = list.head;
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
void deleteHead(LinkedList &list) {
    if (list.head == nullptr) return;
    Node* temp = list.head;
    list.head = list.head->next;
    delete temp;
}

// Xóa phần tử cuối
void deleteTail(LinkedList &list) {
    if (list.head == nullptr) return;
    if (list.head->next == nullptr) {
        delete list.head;
        list.head = nullptr;
        return;
    }
    Node* current = list.head;
    while (current->next->next != nullptr)
        current = current->next;
    delete current->next;
    current->next = nullptr;
}

// Xóa tại vị trí i
void deleteAt(LinkedList &list, int i) {
    if (i == 0) {
        deleteHead(list);
        return;
    }
    Node* current = list.head;
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
void traFor(const LinkedList &list) {
    Node* current = list.head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Duyệt ngược (đệ quy)
void traBackHelper(Node* node) {
    if (node == nullptr) return;
    traverseBackwardHelper(node->next);
    cout << node->data << " ";
}

void traBack(const LinkedList &list) {
    traverseBackwardHelper(list.head);
    cout << endl;
}

// Hàm main chỉ gọi các hàm
int main() {
    LinkedList myList;
    init(myList);

    insertTail(myList, 10);
    insertTail(myList, 20);
    insertHead(myList, 5);
    insertAt(myList, 1, 15);

    cout << "Duyệt xuôi: ";
    traverseForward(myList);

    cout << "Duyệt ngược: ";
    traBack(myList);

    deleteHead(myList);
    deleteTail(myList);
    deleteAt(myList, 0);

    cout << "Sau khi xóa: ";
    traFor(myList);

    cout << "Truy cập phần tử thứ 0: " << access(myList, 0) << endl;

    return 0;
}
