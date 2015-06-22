//author: snassr
#pragma once

//.includes
//..stl library
#include <string>
	//for std::string
#include <algorithm>
	//for std::max
#include <vector>
	//for std::vector
//..armadillo library
#include <armadillo>
	//for arma::mat
//..sLab library
#include "EditDistance.hpp"


//.globals and declarations
/*
*
*
*/




/* Levenshtein Minimum Edit Distance
*
* Definition:
* -----------
* A computation of the distance between two strings D(n,m)
* 		[where n= length of stringOne, m = length of stringTwo]
* This is done via a tabular (matrix) computation by combining solutions to subproblems.
*
* Specific-to-General Solution:
* -----------------------------
* 	1. compute D(i,j) for small i,j (origin 0)
* 	2. compute D(i,j) for consequently larger substrings via character appension until both strings are fully compared at D(n,m)
* 			- compute D(i,j) for all i(0 < i < n) and j(0 < j < m)
*
* Formula:
* --------
* D(i,j) = Min( { D(i-1,j) + 1, //deletion operation from i to compare j
* 				{ D(i,j-1) + 1, //insertion operation to i to compare j
* 				{ D(i-1, j-1) +  2; x(i) != y(j) //substitution character operation in i (deletion & insertion)
* 				{				 0; x(i) == y(j))// to compare j, cost is 0 if no substitution is required, otherwise x (x:the set value of subCost)
*			  )
*
*/




class LevenshteinDistance : public EditDistance
{
	//...member functions
	//...public interface
public:
	//.....overload operators
	//....constructors
	//.....default constructor
	//.....parameterized constructor
		LevenshteinDistance(std::string stringOne, std::string stringTwo, int inSubstitutionCost);
	//.....destructor
	//....operations
	//.....observers
		double calculateDistance();
		double averageStringLengthSimilarity();
		double maximizedStringLengthSimilarity();
		double maximizedStringElementSimilarity();
	//.....mutators
	//...private members
private:
	//....data members
	//....functions
};

//non-member functions




//-------------------------------------------------------------------------------------------implementation---
LevenshteinDistance::LevenshteinDistance(std::string inStringOne, std::string inStringTwo, int inCost) {
	setStringOne(inStringOne);
	setStringTwo(inStringTwo);
	setSubstitutionCost(inCost);
}

double LevenshteinDistance::calculateDistance() {
	std::string strOne = getStringOne();
	std::string strTwo = getStringTwo();
	char charInStrOne = 0;
	char charInStrTwo = 0;
	int matrixRows = getStringOneLength() + 1;
	int matrixCols = getStringTwoLength() + 1;
	int cost;

	arma::mat distanceMatrix(matrixRows, matrixCols, arma::fill::zeros);


	for (int a = 0; a < matrixRows; a++)
		distanceMatrix(a, 0) = a;
	for (int b = 0; b < matrixCols; b++)
		distanceMatrix(0, b) = b;

	for (int rowNum = 1; rowNum < matrixRows; rowNum++) {
		charInStrOne = strOne.at(rowNum - 1);

		for (int colNum = 1; colNum < matrixCols; colNum++) {
			charInStrTwo = strTwo.at(colNum - 1);
			if (charInStrOne == charInStrTwo)
				cost = 0;
			else
				cost = getSubstitutionCost();

		distanceMatrix(rowNum, colNum) = findMinimum(distanceMatrix(rowNum - 1, colNum) + 1, distanceMatrix(rowNum, colNum - 1) + 1, distanceMatrix(rowNum - 1, colNum - 1) + cost);
		}
	}
	return distanceMatrix(getStringOneLength(), getStringTwoLength());
}

double LevenshteinDistance::averageStringLengthSimilarity() { return 0.0; }

double LevenshteinDistance::maximizedStringLengthSimilarity() { return 0.0; }

double LevenshteinDistance::maximizedStringElementSimilarity() { return 0.0; }
