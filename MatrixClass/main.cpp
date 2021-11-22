#include "Class.h"

int main()
{
	Matrix A;
	A.fill();

	/*Matrix B;
	B.fill();
	Matrix E;
	E.makeIdentity();
	Matrix C{ (A.getTranspose() * 3) - (A * B) + (E*2)};
	std::cout << C;*/

	A.transpose();
	std::cout << A;

	std::cout << "\n";
	system("pause");
}