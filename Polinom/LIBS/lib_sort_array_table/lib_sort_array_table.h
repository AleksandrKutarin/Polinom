#ifndef INCLUDE_SORT_ARRAY_TABLE_H_
#define INCLUDE_SORT_ARRAY_TABLE_H_
#include <iostream>
#include <string>
#include <stdexcept>
#include "../../LIBS/lib_interface/lib_interface.h"
#include "../../LIBS/lib_table_array/lib_array_table.h"

using namespace std;

template <class T>
class SortArrayTable : public Itable<T> {
public:
    struct KeyValuePair {
        string key;
        T value;
    };

    int table_size; //внутренний размер
    KeyValuePair* pairs;
    int max_size; //максимальный размер таблицы

    SortArrayTable(int size) {
        table_size = 0;
        pairs = new KeyValuePair[size];
        max_size = size;
    }

    ~SortArrayTable() {
        delete[] pairs;
    }

    void insert(string key, T thing) override {
        if (table_size < max_size) {
            int i = table_size - 1;
            while (i >= 0 && pairs[i].key > key) {
                pairs[i + 1] = pairs[i];
                i--;
            }
            pairs[i + 1].key = key;
            pairs[i + 1].value = thing;
            table_size++;
        }
        else {
            throw string("The table size has been exceeded");
        }
    }

    int find_index(string key) override {
        int l = 0, r = table_size - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (pairs[m].key == key) {
                return m;
            }
            else if (pairs[m].key < key) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return INVALID;
    }

    void remove(string key) override {
        int idx = find_index(key);
        if (idx == INVALID) {
            throw string("element not found");
        }
        for (int i = idx; i < table_size - 1; i++) {
            pairs[i] = pairs[i + 1];
        }
        table_size--;
    }

    T get_by_id(int idx) override {
        if (idx < 0 || idx >= table_size) {
            throw string("Specified index is out of range");
        }
        return pairs[idx].value;
    }

    int size() override {
        return table_size;
    }

    void print() override {
        for (int i = 0; i < table_size; i++) {
            cout << " | " << pairs[i].key << " | " << pairs[i].value << "\n";
        }
    }

    bool isClear() {
        return table_size == 0;
    }
};

#endif