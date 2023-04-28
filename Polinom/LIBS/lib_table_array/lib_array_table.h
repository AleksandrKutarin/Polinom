#ifndef INCLUDE_ARRAY_TABLE_H_
#define INCLUDE_ARRAY_TABLE_H_
#include <iostream>
#include <string>
#include <stdexcept>
#include "../../LIBS/lib_interface/lib_interface.h"

using namespace std;

template <class T>
class ArrayTable : Itable<T> {
public:
	string* keys;		
	T* values;
	int table_size;
	int count_element;

	ArrayTable() {			// конструктор по умолчанию
		table_size = DEFAULT_SIZE;
		count_element = 0;
		keys = new string[table_size];
		values = new T[table_size];
	}
	ArrayTable(int size) {    // конструктор инициализации
		if (size > MAX_SIZE) {
			throw logic_error("–азмер больше максимально допустимого размера таблицы!");
		}
		if (size < MIN_SIZE) {
			throw logic_error("–азмер меньше минимально допустимого размера таблицы!");
		}
		table_size = size;
		count_element = 0;
		keys = new string[table_size];
		values = new T[table_size];
	}
	void writing_to_the_table(string key, int index, T thing) {		// метод записи в таблицу
		keys[index] = key;
		values[index] = thing;
	}
	void insert(string key, T thing) override { // метод добавлени€/обновлени€ элемента в таблицу
		if (full())		// проверка таблицы на полноту, можно ли добавить элемент
		{
			throw logic_error("“аблица переполнена!"); 
		}
		int index = find_index(key);
		if (index == INVALID) {   // если элемента еще нет в таблице
			index = count_element;
			count_element++;
		}
		writing_to_the_table(key, index, thing); // запись
	}
	void remove(string key) override {
		if (empty())		// проверка на пустату таблицы
		{
			throw logic_error("“аблица пуста!");
		}
		int index = find_index(key);
		if (index == INVALID) {
			throw  logic_error("Ќет такого элемента!");
		}
		for (int i = index; i < count_element - 1; i++)
		{
			keys[i] = keys[i + 1];
			values[i] = values[i + 1];
		}
		count_element--;
	}
	int size() override {       // метод возвращени€ количества записаных элементов
		return count_element;
	}
	int buffer_size() {        // метод возвращающий максимальный размер таблицы
		return table_size;
	}
	int find_index(string key) override {   // поиск индекса элемента по ключу
		for (int i = 0; i < count_element; i++)
		{
			if (key == keys[i]) {
				return i;
			}
		}
		return INVALID;
	}
	T get_by_id(int index) override {   // метод возвращает индекс элемента
		return values[index];
	}
	bool full() {			// метод провер€ет заполнина ли таблица
		return table_size == count_element;
	}
	bool empty() {			// метод провер€ет пуста ли таблица
		return count_element == 0;
	}
	void print() override {			// метод печати ключа | элемента
		for (int i = 0; i < count_element; i++)
		{
			cout << keys[i] << " | " << values[i] << endl;
		}
		
	}
};

#endif