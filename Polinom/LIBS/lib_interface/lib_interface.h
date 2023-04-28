#ifndef INCLUDE_INTERFACE_H_
#define INCLUDE_INTERFACE_H_

#define MIN_SIZE 1
#define DEFAULT_SIZE 20
#define MAX_SIZE 50
#define INVALID -1

#include <iostream>
using namespace std;

template <typename T>
class Itable{
public:
	virtual void insert(string key, T thing) = 0;
	virtual void remove(T thing) = 0;
	virtual int find_index(string key) = 0;
	virtual void print() = 0;
	virtual T get_by_id(int index) = 0;
	virtual int size() = 0;
};

#endif