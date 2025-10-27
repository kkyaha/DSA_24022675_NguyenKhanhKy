#include <iostream>
#include <string>
#include <list>
#include <utility> // std::pair

using namespace std;

struct SymbolTableStdList {
    list<pair<int, int>> data;

    int size() { return data.size(); }
    bool isEmpty() { return data.empty(); }

    // O(N)
    void put(int key, int value) {
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (it->first == key) {
                it->second = value;
                return;
            }
        }
        data.push_back({key, value});
    }

    // O(N)
    bool get(int key, int& outValue) {
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (it->first == key) {
                outValue = it->second; 
                return true;           
            }
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
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (it->first == key) {
                data.erase(it);
                return;
            }
        }
    }
};