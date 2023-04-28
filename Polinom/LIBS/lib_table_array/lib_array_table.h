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

	ArrayTable() {			// ����������� �� ���������
		table_size = DEFAULT_SIZE;
		count_element = 0;
		keys = new string[table_size];
		values = new T[table_size];
	}
	ArrayTable(int size) {    // ����������� �������������
		if (size > MAX_SIZE) {
			throw logic_error("������ ������ ����������� ����������� ������� �������!");
		}
		if (size < MIN_SIZE) {
			throw logic_error("������ ������ ���������� ����������� ������� �������!");
		}
		table_size = size;
		count_element = 0;
		keys = new string[table_size];
		values = new T[table_size];
	}
	void writing_to_the_table(string key, int index, T thing) {		// ����� ������ � �������
		keys[index] = key;
		values[index] = thing;
	}
	void insert(string key, T thing) override { // ����� ����������/���������� �������� � �������
		if (full())		// �������� ������� �� �������, ����� �� �������� �������
		{
			throw logic_error("������� �����������!"); 
		}
		int index = find_index(key);
		if (index == INVALID) {   // ���� �������� ��� ��� � �������
			index = count_element;
			count_element++;
		}
		writing_to_the_table(key, index, thing); // ������
	}
	void remove(string key) override {
		if (empty())		// �������� �� ������� �������
		{
			throw logic_error("������� �����!");
		}
		int index = find_index(key);
		if (index == INVALID) {
			throw  logic_error("��� ������ ��������!");
		}
		for (int i = index; i < count_element - 1; i++)
		{
			keys[i] = keys[i + 1];
			values[i] = values[i + 1];
		}
		count_element--;
	}
	int size() override {       // ����� ����������� ���������� ��������� ���������
		return count_element;
	}
	int buffer_size() {        // ����� ������������ ������������ ������ �������
		return table_size;
	}
	int find_index(string key) override {   // ����� ������� �������� �� �����
		for (int i = 0; i < count_element; i++)
		{
			if (key == keys[i]) {
				return i;
			}
		}
		return INVALID;
	}
	T get_by_id(int index) override {   // ����� ���������� ������ ��������
		return values[index];
	}
	bool full() {			// ����� ��������� ��������� �� �������
		return table_size == count_element;
	}
	bool empty() {			// ����� ��������� ����� �� �������
		return count_element == 0;
	}
	void print() override {			// ����� ������ ����� | ��������
		for (int i = 0; i < count_element; i++)
		{
			cout << keys[i] << " | " << values[i] << endl;
		}
		
	}
};

#endif