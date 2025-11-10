#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <list>

using namespace std;
enum State { EMPTY, OCCUPIED, DELETED };

struct HashSlot {
    string key;
    int value;
    State state;

    HashSlot() : state(EMPTY), value(0) {}
};

struct HashTableOpenAddressing {
private:
    vector<HashSlot> table;
    int capacity;
    int currentSize;

    size_t hashFunction(string key) {
        return std::hash<string>{}(key) % capacity;
    }

public:
    HashTableOpenAddressing(int cap = 10) : capacity(cap), currentSize(0) {
        table.resize(capacity);
    }

    void insert(string key, int value) {
        size_t index = hashFunction(key);
        int deletedSlot = -1;

        for (int i = 0; i < capacity; ++i) {
            size_t probeIndex = (index + i) % capacity;

            if (table[probeIndex].state == EMPTY) {
                int insertPos = (deletedSlot != -1) ? deletedSlot : probeIndex;
                table[insertPos].key = key;
                table[insertPos].value = value;
                table[insertPos].state = OCCUPIED;
                currentSize++;
                return;
            }
            if (table[probeIndex].state == OCCUPIED && table[probeIndex].key == key) {
                table[probeIndex].value = value;
                return;
            }
            if (table[probeIndex].state == DELETED && deletedSlot == -1) {
                deletedSlot = probeIndex;
            }
        }
    }

    bool get(string key, int& outValue) {
        size_t index = hashFunction(key);

        for (int i = 0; i < capacity; ++i) {
            size_t probeIndex = (index + i) % capacity;

            if (table[probeIndex].state == EMPTY) {
                return false;
            }
            if (table[probeIndex].state == OCCUPIED && table[probeIndex].key == key) {
                outValue = table[probeIndex].value;
                return true;
            }
        }
        return false;
    }

    void remove(string key) {
        size_t index = hashFunction(key);

        for (int i = 0; i < capacity; ++i) {
            size_t probeIndex = (index + i) % capacity;

            if (table[probeIndex].state == EMPTY) {
                return;
            }
            if (table[probeIndex].state == OCCUPIED && table[probeIndex].key == key) {
                table[probeIndex].state = DELETED;
                currentSize--;
                return;
            }
        }
    }
}