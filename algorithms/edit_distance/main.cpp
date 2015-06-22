#include <iostream>
#include "EditDistance.hpp"
#include "LevenshteinDistance.hpp"


int main()
{
	std::cout << "hello world!!!" << std::endl;
	std::cout << std::endl;

	EditDistance* matrix = new LevenshteinDistance("INTENTION", "EXECUTION", 2);
	std::cout << "WORD 1: " << matrix->getStringOne() << std::endl;
	std::cout << "wORD 2: " << matrix->getStringTwo() << std::endl;
	std::cout << "WORD 1 LENGTH: " << matrix->getStringOneLength() << std::endl;
	std::cout << "WORD 2 LENGTH: " << matrix->getStringTwoLength() << std::endl;
	std::cout << "Levenshtein Distance: " << matrix->calculateDistance() << std::endl;

	for (int a = 0; a < matrix->getStringOneLength() + 1; a++)
		std::cout << a << std::endl;

	arma::mat distMatr(10, 10, arma::fill::zeros);
	distMatr.print();
}


