// Copyright 2023 Kutarin Alexandr

#include <iostream>
#include <vector>
#include "../../LIBS/lib_table_array/lib_array_table.h"
#include "../../LIBS/lib_For_Polinom/lib_func.h"
#include "../../LIBS/lib_hash_table/lib_hash_table.h"
#include "../../LIBS/lib_list/lib_list.h"
#include "../../LIBS/lib_list_table/lib_list_table.h"
#include "../../LIBS/lib_sort_array_table/lib_sort_array_table.h"
using namespace std;

void test() {

    /*ArrayTable<string> table;
    table.insert("obj1", "obj2");
    table.insert("obj2", "obj3");
    table.insert("obj3", "obj4");
    table.print();
    cout << "---------------" << endl;
    table.remove("obj1");
    table.print();*/
    /*ListTable<string> l;
    l.insert("kb", "pivo");
    l.insert("bristol", "pivo");
    l.insert("spar", "pivo");
    l.print();
    cout << "=================" << endl;
    l.remove("spar");
    l.print();*/
    /*hash_table<string> h;
    h.insert("kb", "pivo");
    h.insert("bristol", "pivo");
    h.insert("spar", "pivo");
    h.print();
    cout << "=================" << endl;
    h.remove("spar");
    h.remove("kb");
    h.print();*/
    SortArrayTable<string> ar(10);
    ar.insert("kb", "pivo");
    ar.insert("bristol", "pivo");
    ar.insert("spar", "pivo");
    ar.print();
    cout << "=================" << endl;
    ar.remove("spar");
    ar.remove("kb");
    ar.print();

}