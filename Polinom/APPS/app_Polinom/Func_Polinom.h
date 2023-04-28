// Copyright 2023 Kutarin Alexandr

#include <iostream>
#include <vector>
#include "../../LIBS/lib_table_array/lib_array_table.h"
#include "../../LIBS/lib_For_Polinom/lib_func.h"
using namespace std;

void test() {

    ArrayTable<string> table;
    table.insert("obj1", "obj2");
    table.insert("obj2", "obj3");
    table.insert("obj3", "obj4");
    table.print();
    cout << "---------------" << endl;
    table.remove("obj1");
    table.print();


}