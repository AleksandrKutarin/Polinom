#ifndef INCLUDE_LIST_TABLE_H_
#define INCLUDE_LIST_TABLE_H_
#include <iostream>
#include <string>
#include <stdexcept>
#include "../../LIBS/lib_interface/lib_interface.h"
#include "../../LIBS/lib_list/lib_list.h"

using namespace std;

template <class T>
class ListTable : Itable<T> {
public:
	int table_size; //внутренний размер
	CList<pair<string, T>> pairs;

	ListTable() {      // конструктор по умолчанию
		table_size = NULL;
		pairs = CList<pair<string, T>>();
	}

	void writing_to_the_table(string key, int index, T thing) {    // метод записи в таблицу
		if (index >= table_size) {
			throw string("Specified index is out of range");
		}
		else {
			pairs[index]->set_data(pair<string, T>(key, thing));
		}
	}
	void insert(string key, T thing) override { // метод добавления/обновления элемента в таблицу
		int idx = find_index(key);
		if (idx == INVALID) {
			pairs.push_back(pair<string, T>(key, thing));
			table_size++;
		}
		else {
			pairs[idx]->set_data(pair<string, T>(key, thing));
		}
	}
	int find_index(string key) override {   // поиск индекса элемента по ключу
		if (isClear()) {
			return INVALID;
		}
		CNode<pair<string, T>>* node = pairs.front();
		for (int idx = 0; node != nullptr; ++idx) {
			if (node->get_data().first == key) {
				return idx;
			}
			node = node->next;
		}
		return INVALID;
	}
	void remove(string key) override {
		if (isClear()) {
			throw string("Table is clear");
		}
		else {
			int idx = find_index(key);
			if (idx == INVALID) {
				throw string("element not found");
			}
			else {
				pairs.erase(idx);
				table_size--;
			}
		}
	}
	T get_by_id(int idx) override {
		return pairs[idx]->get_data().second;
	}
	int size() override {
		return table_size;
	}
	void print() override {
		for (int i = 0; i < table_size; i++) {
			cout << " | " << pairs[i]->get_data().first << " | " << pairs[i]->get_data().second << "\n";
		}
	}
	bool isClear() {
		return table_size == 0;
	}
};

#endif