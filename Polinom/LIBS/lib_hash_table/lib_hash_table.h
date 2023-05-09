#ifndef INCLUDE_HASH_TABLE_H_
#define INCLUDE_HASH_TABLE_H_
#include <iostream>
#include <string>
#include <stdexcept>
#include <list>
#include "../../LIBS/lib_hash_table/lib_hash_table.h"
#include "../../LIBS/lib_interface/lib_interface.h"

using namespace std;

template<class T>
class hash_table {
public:
	list<pair<string, T>>* list_table;

	int size_table;
	int count_obj;
	int index_array;
	int hashFunc(string key) {
		int result_idx = 0;
		for (const auto elem : key) {
			result_idx += abs((int)elem);
		}
		return result_idx % size_table;
	}

	void write_in_table(string key, T tbl_obj, int idx) {
		if (idx == 0) {
			list_table[index_array].push_back(pair<string, T>(key, tbl_obj));
		}
		else {
			int i = 0;
			for (auto it = list_table[index_array].begin(); it != list_table[index_array].end(); it++) {
				if (i == idx) {
					*it = pair<string, T>(key, tbl_obj);
				}
				else {
					i++;
				}
			}
		}
	}
	hash_table() {
		size_table = 10;
		list_table = new list<pair<string, T>>[size_table];
		count_obj = 0;
		index_array = 0;
	}
	hash_table(int size) {
		if (size < 1) {
			throw string("Введенный размер меньше минимального, ошибка в конструкторе!");
		}
		if (size > 100)
		{
			throw string("Введенный размер больше максимального, ошибка в конструкторе!");
		}
		size_table = size;
		list_table = new list<pair<string, T>>[size_table];
		count_obj = 0;
		index_array = 0;
	}
	void insert(string key, T tbl_obj) {
		if (isFull()) {
			throw string("Таблица заполнена, ошибка в методе вставки!");
		}
		int idx = find_index(key);
		if (idx != -1) {
			throw string("В таблице уже есть экземпляр с таким же именем, ошибка в методе insert!");
		}
		write_in_table(key, tbl_obj, 0);
		count_obj++;
	}
	void update(string key, T tbl_obj) {
		int idx = find_index(key);
		if (idx == -1) {
			throw string("Указанный элемент не найден, ошибка в методе обновления!");
		}
		write_in_table(key, tbl_obj, idx);
	}
	void remove(string key) {
		if (isClear()) {
			throw string("Таблица чиста, ошибка в методе удаления!");
		}
		int idx = find_index(key);
		if (idx == -1) {
			throw string("Указанный элемент не найден, ошибка в методе удаления!");
		}
		list_table[index_array].remove({ key, get_by_id(idx) });
	}
	int find_index(string key) {
		index_array = hashFunc(key);
		int i = 0;
		if (!list_table[index_array].empty()) {
			for (auto it = list_table[index_array].begin(); it != list_table[index_array].end(); it++) {
				if (key == (*it).first) {
					return i;
				}
				else {
					i++;
				}
			}
		}
		return -1;
	}
	T get_by_id(int idx) {
		int i = 0;
		T obj;
		for (auto it = list_table[index_array].begin(); it != list_table[index_array].end(); it++) {
			if (i == idx) {
				return (*it).second;
			}
			else {
				i++;
			}
		}
		return T();
	}
	int size() {
		return size_table;
	}
	int get_number_objects() {
		return count_obj;
	}
	void print() {
		for (int i = 0; i < size_table; i++) {
			if (!list_table[i].empty()) {
				for (auto it = list_table[i].begin(); it != list_table[i].end(); it++) {
					cout << (*it).first << " | " << (*it).second << endl;
				}
			}
		}
	}
	int get_temp_index_buffer() {
		return index_array;
	}
	void set_temp_index_buffer(int value) {
		if (value > size_table) {
			throw string("Слишком большое значение, превышающее размер текущей таблицы!");
		}
		if (value < 1) {
			throw string("очень маленькое значение");
		}
		index_array = value;
	}
	bool isClear() {
		return count_obj == 0;
	}
	bool isFull() {
		return count_obj >= 10000;
	}
	~hash_table() {}
};

#endif