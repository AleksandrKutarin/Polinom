#ifndef INCLUDE_FUNC_H_
#define INCLUDE_FUNC_H_
#include <iostream>
#include <ostream>
#include <vector>
#include <cmath>
#include "../../LIBS/lib_For_Polinom/lib_func.h"
#include "../../LIBS/lib_list/lib_list.h"
using namespace std;

template <class T>
class Polinom {
public:
    vector<T> coeff;

    Polinom() {}
    Polinom(vector<T>& coeffs) : coeff(coeffs) {}

    Polinom operator+ (const Polinom& other);
    Polinom operator- (const Polinom& other);
    Polinom operator* (const Polinom& other);
    Polinom operator* (const T& constant);

    T evaluate(const T& x);
    Polinom derivative();
    Polinom integral();
    string to_string();
};
template <class T>
Polinom<T> Polinom<T>::operator+ (const Polinom& other) {
    size_t size = std::max(coeff.size(), other.coeff.size());
    std::vector<T> result(size, 0.0);
    for (size_t i = 0; i < size; ++i) {
        if (i < coeff.size()) result[i] += coeff[i];
        if (i < other.coeff.size()) result[i] += other.coeff[i];
    }
    return Polinom(result);

}
template <class T>
Polinom<T> Polinom<T>::operator- (const Polinom& other) {
    size_t size = std::max(coeff.size(), other.coeff.size());
    std::vector<T> result(size, 0.0);
    for (size_t i = 0; i < size; ++i) {
        if (i < coeff.size()) result[i] += coeff[i];
        if (i < other.coeff.size()) result[i] -= other.coeff[i];
    }
    return Polinom(result);
}
template <class T>
Polinom<T> Polinom<T>::operator* (const Polinom& other) {
    size_t size = coeff.size() + other.coeff.size() - 1;
    std::vector<T> result(size, 0.0);
    for (size_t i = 0; i < coeff.size(); ++i) {
        for (size_t j = 0; j < other.coeff.size(); ++j) {
            result[i + j] += coeff[i] * other.coeff[j];
        }
    }
    return Polinom(result);
}
template <class T>
Polinom<T> Polinom<T>::operator* (const T& constant) {
    std::vector<T> result(coeff.size(), 0.0);
    for (size_t i = 0; i < coeff.size(); ++i) {
        result[i] = coeff[i] * constant;
    }
    return Polinom(result);
}

template <class T>
T Polinom<T>::evaluate(const T& x) {
    T res = 0.0;
    for (size_t i = 0; i < coeff.size(); ++i) {
        res += coeff[i] * pow(x, i);
    }
    return res;
}
template <class T>
Polinom<T> Polinom<T>::derivative() {
    if (coeff.size() <= 1) return Polinom();
    std::vector<T> result(coeff.size() - 1, 0.0);
    for (size_t i = 1; i < coeff.size(); ++i) {
        result[i - 1] = i * coeff[i];
    }
    return Polinom(result);
}
template <class T>
Polinom<T> Polinom<T>::integral() {
    std::vector<T> result(coeff.size() + 1, 0.0);
    for (size_t i = 0; i < coeff.size(); ++i) {
        result[i + 1] = coeff[i] / (i + 1);
    }
    return Polinom(result);

}
template <class T>
string Polinom<T>::to_string() {
    int size = coeff.size();
    string str = "";
    if (size <= 0) {
        throw string("zero size");
    }
    switch (size) {
    case 1:
        str += std::to_string(coeff[0]);
        break;
    case 2:
        str += std::to_string(coeff[0]);
        str += "+";
        str += std::to_string(coeff[1]);
        break;
    default:
        str += std::to_string(coeff[0]);
        str += "+";
        str += std::to_string(coeff[1]);
        for (int i = 2; i < size; i++) {
            str += "+";
            str += std::to_string(coeff[i]);
            str += "x^";
            str += std::to_string(i);
        }
        break;
    }
    return str;
}
#endif