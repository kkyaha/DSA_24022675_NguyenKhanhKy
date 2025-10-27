#include <iostream>
#include <string>

using namespace std;

struct SymbolTableLinkedList {
    struct Node {
        int key;
        int value;
        Node* next;

        Node(int k, int v, Node* n) : key(k), value(v), next(n) {}
    };

    Node* head;
    int n;

    SymbolTableLinkedList() : head(nullptr), n(0) {}

    int size() { return n; }
    bool isEmpty() { return n == 0; }

    // O(N)
    void put(int key, int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        head = new Node(key, value, head);
        n++;
    }

    // O(N)
    bool get(int key, int& outValue) {
        Node* current = head;
        while (current != nullptr) {
            if (current->key == key) {
                outValue = current->value; 
                return true;               
            }
            current = current->next;
        }
        return false; 
    }

    // O(N)
    bool contains(int key) {
        int tempValue; 
        return get(key, tempValue);
    }

    // O(N)
    void remove(int key) {
        if (head == nullptr) return;
        if (head->key == key) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            n--;
            return;
        }

        Node* prev = head;
        Node* current = head->next;
        while (current != nullptr) {
            if (current->key == key) {
                prev->next = current->next;
                delete current;
                n--;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
};