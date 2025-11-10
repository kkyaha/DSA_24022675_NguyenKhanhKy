#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <list>

using namespace std;

//SEPARATE CHAINING

struct Node {
    string key;
    int value;
    Node* next;
    Node(string k, int v) : key(k), value(v), next(nullptr) {}
};

struct HashTableSeparateChaining {
private:
    vector<Node*> table;
    int capacity;
    int currentSize;
    size_t hashFunction(string key) {
        return std::hash<string>{}(key) % capacity;
    }

public:
    HashTableSeparateChaining(int cap = 10) : capacity(cap), currentSize(0) {
        table.resize(capacity, nullptr);
    }

    void insert(string key, int value) {
        size_t index = hashFunction(key);
        Node* cur = table[index];
        Node* prev = nullptr;

        while (cur != nullptr) {
            if (cur->key == key) {
                cur->value = value;
                return;
            }
            prev = cur;
            cur = cur->next;
        }

        Node* newNode = new Node(key, value);
        if (prev == nullptr) {
            table[index] = newNode;
        } else {
            prev->next = newNode;
        }
        currentSize++;
    }

    bool get(string key, int& outValue) {
        size_t index = hashFunction(key);
        Node* cur = table[index];

        while (cur != nullptr) {
            if (cur->key == key) {
                outValue = cur->value;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    void remove(string key) {
        size_t index = hashFunction(key);
        Node* cur = table[index];
        Node* prev = nullptr;

        while (cur != nullptr && cur->key != key) {
            prev = cur;
            cur = cur->next;
        }

        if (cur == nullptr) return;

        if (prev == nullptr) {
            table[index] = cur->next;
        } else {
            prev->next = cur->next;
        }

        delete cur;
        currentSize--;
    }
};
