// MatrixMultiplication.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;


template <typename T>
class M {
public:
	T* data = nullptr;
	uint16_t rows = 0;
	uint16_t columns = 0;
	M(uint16_t rows, uint16_t columns) :  rows(rows), columns(columns) {
		data = new T[rows*columns];
		memset(data, (T)(0), rows * columns);
	}
	~M() {
		delete[] data;
	}

	// Overloaded assignment
	M<T>& operator= (const M<T>& fraction);

	template <typename U>
	friend ostream& operator<<(ostream& os, const M<U>& m);

	T* begin() { return data; }
	T* end() { return data+rows*columns; }
	T& at(uint16_t row, uint16_t col) const { return *(data + row * columns + col); }
};

template <typename T>
M<T>& M<T>::operator= (const M<T>& m) {
	
	delete[] data;
	data = new T[m.rows * m.columns];
	rows = m.rows;
	columns = m.columns;
	memccpy(data, m.data, m.rows * m.columns);
	return *this;
}

template <typename U>
ostream& operator<<(ostream& os, const M<U>& m) {
	for (int i = 0; i < m.rows; i++) {
		for (int j = 0; j < m.columns; j++)
			os << to_string(m.at(i, j)) << ' ';
		os << std::endl;
	}
	return os;
}

template <typename T> 
M<T> multiplyMatrix(M<T>* left, M<T>* right) {
	if (left->columns != right->rows)
		throw std::invalid_argument("Matrices dimensions do not match. Multiplication not possible");
	
	M<T> result(left->rows, right->columns);
	uint16_t dimension = left->columns;

	for (int rRow = 0; rRow < left->rows; rRow++) {
		for (int rCol = 0; rCol < right->columns; rCol++) {
			T* p = result.data + rRow * right->columns + rCol;
			for (int i = 0; i < dimension; i++) {
				result.at(rRow,rCol) += left->at(rRow,i) * right->at(i,rCol);
			}
		}
	}
	return result;
}
// TODO: Reference additional headers your program requires here.
