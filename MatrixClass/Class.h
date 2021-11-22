#pragma once
#include <iostream>

class Matrix
{
private:
	int m_array[3][3];
	int m_row = 3;
	int m_col = 3;
public:
	Matrix();
	Matrix(const Matrix& from);

	void fill();			//пользовательским вводом
	void transpose();		//транспортация вызывающего объекта
	Matrix getTranspose();	//возвращает транспортированную матрицу
	void makeIdentity();	//создать единичную матрицу
	int det3x3();			//детерминировать правилом треугольников

	friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix);
	Matrix operator+(const Matrix& right);
	Matrix operator-(const Matrix& right);
	Matrix operator*(const Matrix& right);
	Matrix& operator*(const int& multiplyer);
	Matrix& operator=(const Matrix& right);
};