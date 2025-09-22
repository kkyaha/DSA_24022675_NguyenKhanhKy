#include <iostream>
using namespace std;

const int MAX = 100;

struct List {
    int data[MAX];
    int size;
};

// Khởi tạo danh sách
void init(List &l) {
    l.size = 0;
}

// Truy cập phần tử tại vị trí i
int access(const List &l, int i) {
    if (i >= 0 && i < l.size)
        return l.data[i];
}

// Chèn phần tử vào đầu
void insertHead(List &l, int value) {
    if (l.size >= MAX) return;
    for (int i = l.size; i > 0; i--)
        l.data[i] = l.data[i - 1];
    l.data[0] = value;
    l.size++;
}

// Chèn phần tử vào cuối
void insertTail(List &l, int value) {
    if (l.size >= MAX) return;
    l.data[l.size++] = value;
}

// Chèn vào vị trí i
void insertAt(List &l, int i, int value) {
    if (l.size >= MAX || i < 0 || i > l.size) return;
    for (int j = l.size; j > i; j--)
        l.data[j] = l.data[j - 1];
    l.data[i] = value;
    l.size++;
}

// Xóa phần tử đầu
void deleteHead(List &l) {
    if (l.size == 0) return;
    for (int i = 0; i < l.size - 1; i++)
        l.data[i] = l.data[i + 1];
    l.size--;
}

// Xóa phần tử cuối
void deleteTail(List &l) {
    if (l.size == 0) return;
    l.size--;
}

// Xóa tại vị trí i
void deleteAt(List &l, int i) {
    if (i < 0 || i >= l.size) return;
    for (int j = i; j < l.size - 1; j++)
        l.data[j] = l.data[j + 1];
    l.size--;
}

// Duyệt xuôi
void traFor(const List &l) {
    for (int i = 0; i < l.size; i++)
        cout << l.data[i] << " ";
    cout << endl;
}

// Duyệt ngược
void traBack(const List &l) {
    for (int i = l.size - 1; i >= 0; i--)
        cout << l.data[i] << " ";
    cout << endl;
}

// Hàm main chỉ gọi các hàm
int main() {
    List myList;
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
