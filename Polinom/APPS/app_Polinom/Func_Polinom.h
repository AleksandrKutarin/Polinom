// Copyright 2023 Kutarin Alexandr

#include <iostream>
#include <vector>
#include <conio.h>
#include "../../LIBS/lib_table_array/lib_array_table.h"
#include "../../LIBS/lib_For_Polinom/lib_func.h"
#include "../../LIBS/lib_hash_table/lib_hash_table.h"
#include "../../LIBS/lib_list/lib_list.h"
#include "../../LIBS/lib_list_table/lib_list_table.h"
#include "../../LIBS/lib_sort_array_table/lib_sort_array_table.h"

using namespace std;

void PolinomTest();
void ArrayTableTest();
void ListTableTest();
void HashTableTest();
void SortArrayTableTest();

void test() {
    while (true) {
        system("cls");
        cout << "Test menu: \n1) Polinom \n2) ArrayTable \n3) ListTable \n4) HashTable \n5) SortArrayTable \nEnter: ";
        char c = getch();
        system("cls");
        switch (c) {
        case '1': 
            cout << "\tPolinom" << endl;
            PolinomTest();
            break;
        case '2': 
            cout << "\tArrayTable" << endl;
            ArrayTableTest();
            break;
        case '3': 
            cout << "\tListTable" << endl;
            ListTableTest();
            break;
        case '4':
            cout << "\tHashTable" << endl;
            HashTableTest();
            break;
        case '5':
            cout << "\tSortArrayTable" << endl;
            SortArrayTableTest();
            break;
        default:
            cout << "Wrong answer!";
            break;
        }
        cout << "\nPress any button to exit the menu: ";
        getch();
    }
}
void PolinomTest() {
    
    vector<int> a{ 1, 2, 3 }; 
    vector<int> b{ 4, 5 }; 

    Polinom<int> p(a), q(b);
    Polinom<int> r = p + q;
    Polinom<int> s = p - q;
    Polinom<int> t = p * q;
    Polinom<int> u = p * 2.0;

    cout << "p(x) = " << a[0] << " + " << a[1] << "x + " << a[2] << "x^2" << endl;
    cout << "q(x) = " << b[0] << " + " << b[1] << "x" << endl;
    cout << "p(x) + q(x) = " << r.evaluate(1) << endl;
    cout << "p(x) - q(x) = " << s.evaluate(1) << endl;
    cout << "p(x) * q(x) = " << t.evaluate(1) << endl;
    cout << "2 * p(x) = " << u.evaluate(1) << endl;

    Polinom d = p.derivative();
    cout << "p'(x) = " << d.evaluate(1) << endl;

    Polinom i = p.integral();
    cout << "Integral of p(x) = " << i.evaluate(1) << endl;
}
void ArrayTableTest() {
    ArrayTable<string> pol;
    vector<int> a{ 1, 2, 3, 5 };
    vector<int> b{ 2, 1, 5 };
    Polinom<int> p1(a);
    Polinom<int> p2(b);
    pol.insert("pol1", p1.to_string());
    pol.insert("pol3", p2.to_string());
    pol.insert("pol4", p1.to_string());
    pol.insert("pol5", p1.to_string());
    pol.insert("pol6", p2.to_string());
    pol.insert("pol7", p1.to_string());
    pol.insert("pol8", p2.to_string());
    pol.insert("pol9", p1.to_string());
    pol.insert("pol2", p2.to_string());
    pol.print();
    cout << " ------------------------\n";
    pol.remove("pol2");
    pol.print();
}
void ListTableTest() {
    ListTable<string> l;
    vector<int> a{ 2, 3, 5, 7, 8 };
    vector<int> b{ 5, 3, 2, 10 };
    Polinom<int> p1(a);
    Polinom<int> p2(b);
    l.insert("pol1", p1.to_string());
    l.insert("pol2", p2.to_string());
    l.print();
    cout << " ------------------------\n";
    l.remove("pol1");
    l.print();
}
void HashTableTest() {
    hash_table<string> h(2);
    vector<int> a{ 1, 5, 7, 8 };
    vector<int> b{ 2, 1, 2, 10 };
    Polinom<int> p1(a);
    Polinom<int> p2(b);
    h.insert("pol1", p1.to_string());
    h.insert("pol2", p2.to_string());
    h.insert("pol3", p1.to_string());
    h.print();
    cout << " ------------------------\n";
    h.remove("pol2");
    h.print();
}
void SortArrayTableTest() {
    SortArrayTable<string> ar(10);
    vector<int> a{ 3, 5, 7, 8, 1 };
    vector<int> b{ 2, 1, 5, };
    Polinom<int> p1(a);
    Polinom<int> p2(b);
    ar.insert("pol2", p1.to_string());
    ar.insert("pol4", p2.to_string());
    ar.insert("pol1", p2.to_string());
    ar.insert("pol3", p1.to_string());
    ar.print();
    cout << " ------------------------\n";
    ar.remove("pol2");
    ar.print();
}