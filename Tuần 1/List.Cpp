#include <iostream>
using namespace std;

const int MAX = 100;

struct List {
    int data[MAX];
    int size;

    // Constructor thay cho init()
    List() {
        size = 0;
    }

    // Truy cập phần tử tại vị trí i
    int access(int i) const {
        if (i >= 0 && i < size)
            return data[i];
    }

    // Chèn phần tử vào đầu
    void insertHead(int value) {
        if (size >= MAX) return;
        for (int i = size; i > 0; i--)
            data[i] = data[i - 1];
        data[0] = value;
        size++;
    }

    // Chèn phần tử vào cuối
    void insertTail(int value) {
        if (size >= MAX) return;
        data[size++] = value;
    }

    // Chèn vào vị trí i
    void insertAt(int i, int value) {
        if (size >= MAX || i < 0 || i > size) return;
        for (int j = size; j > i; j--)
            data[j] = data[j - 1];
        data[i] = value;
        size++;
    }

    // Xóa phần tử đầu
    void deleteHead() {
        if (size == 0) return;
        for (int i = 0; i < size - 1; i++)
            data[i] = data[i + 1];
        size--;
    }

    // Xóa phần tử cuối
    void deleteTail() {
        if (size == 0) return;
        size--;
    }

    // Xóa tại vị trí i
    void deleteAt(int i) {
        if (i < 0 || i >= size) return;
        for (int j = i; j < size - 1; j++)
            data[j] = data[j + 1];
        size--;
    }

    // Duyệt xuôi
    void traverseForward() const {
        for (int i = 0; i < size; i++)
            cout << data[i] << " ";
        cout << endl;
    }

    // Duyệt ngược
    void traverseBackward() const {
        for (int i = size - 1; i >= 0; i--)
            cout << data[i] << " ";
        cout << endl;
    }
};

// Hàm main
int main() {
    List myList;

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
