#include "Class.h"

Matrix::Matrix()
{
	for (int row = 0; row < m_row; row++)
	{
		for (int col = 0; col < m_col; col++)
		{
			m_array[row][col] = 0;
		}
	}
}

Matrix::Matrix(const Matrix& from)
{
	for (int row = 0; row < m_row; row++)
	{
		for (int col = 0; col < m_col; col++)
		{
			m_array[row][col] = from.m_array[row][col];
		}
	}
}

void Matrix::fill()
{
	std::cout << "\n\n\a";
	for (int row = 0; row < m_row; row++)
	{
		for (int col = 0; col < m_col; col++)
		{
			while (true)
			{
				std::cout << "Enter i" << row + 1 << " j" << col + 1 << " : ";
				int x{};
				std::cin >> x;
				if (!std::cin.fail())
				{
					m_array[row][col] = x;
					break;
				}
				else
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
				}
			}
		}
	}
	std::cout << "\n\n";
}

void Matrix::transpose()
{
	Matrix temp;
	for (int row = 0; row < m_row; row++)		//транспортируем, записывая во временный объект.
	{
		for (int col = 0; col < m_col; col++)
		{
			temp.m_array[col][row] = m_array[row][col];
		}
	}

	for (int row = 0; row < m_row; row++)		//заменяем из временного объекта.
	{
		for (int col = 0; col < m_col; col++)
		{
			std::swap(m_array[row][col], temp.m_array[row][col]);
		}
	}
}

Matrix Matrix::getTranspose()
{
	Matrix temp;
	for (int row = 0; row < m_row; row++)		//транспортируем, записывая во временный объект.
	{
		for (int col = 0; col < m_col; col++)
		{
			temp.m_array[col][row] = m_array[row][col];
		}
	}
	return temp;
}

void Matrix::makeIdentity()
{
	for (int row = 0; row < m_row; row++)
	{
		for (int col = 0; col < m_col; col++)
		{
			if (row == col)
			{
				m_array[row][col] = 1;
			}
			else
			{
				m_array[row][col] = 0;
			}
		}
	}
}

int Matrix::det3x3()
{
	return	(m_array[0][0] * m_array[1][1] * m_array[2][2])
		+
		(m_array[0][2] * m_array[0][1] * m_array[2][1])
		+
		(m_array[0][1] * m_array[1][2] * m_array[2][0])
		-
		(m_array[0][2] * m_array[1][1] * m_array[2][0])
		-
		(m_array[0][0] * m_array[1][2] * m_array[2][1])
		-
		(m_array[0][1] * m_array[1][0] * m_array[2][2]);
}

Matrix Matrix::operator+(const Matrix& right)
{
	Matrix temp;
	for (int row = 0; row < m_row; row++)
	{
		for (int col = 0; col < m_col; col++)
		{
			temp.m_array[row][col] = right.m_array[row][col] + m_array[row][col];
		}
	}
	return temp;
}

Matrix Matrix::operator-(const Matrix& right)
{
	Matrix temp;
	for (int row = 0; row < m_row; row++)
	{
		for (int col = 0; col < m_col; col++)
		{
			temp.m_array[row][col] = m_array[row][col] - right.m_array[row][col];
		}
	}
	return temp;
}

Matrix Matrix::operator*(const Matrix& right)
{
	Matrix temp;
	for (int cRow = 0; cRow < m_row; cRow++)
	{
		for (int cCol = 0; cCol < m_col; cCol++)
		{
			for (int index = 0; index < m_row; index++)
			{
				temp.m_array[cRow][cCol] += (m_array[cRow][index] * right.m_array[index][cCol]);
			}
		}
	}
	return temp;
}

Matrix& Matrix::operator*(const int& multiplyer)
{
	for (int row = 0; row < m_row; row++)
	{
		for (int col = 0; col < m_col; col++)
		{
			m_array[row][col] = m_array[row][col] * multiplyer;
		}
	}
	return *this;
}

Matrix& Matrix::operator=(const Matrix& right)
{
	for (int row = 0; row < m_row; row++)
	{
		for (int col = 0; col < m_col; col++)
		{
			m_array[row][col] = right.m_array[row][col];
		}
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Matrix& matrix)
{
	for (int row = 0; row < matrix.m_row; row++)
	{
		for (int col = 0; col < matrix.m_col; col++)
		{
			out << matrix.m_array[row][col] << "\t";
		}
		out << "\n";
	}
	out << "\n\n";
	return out;
}