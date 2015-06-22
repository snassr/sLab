//author: snassr
#pragma once

//.includes
//..stl library
#include <cstddef>
	//for std::null
#include <algorithm>
	//for std::min
#include <locale>
#include <vector>
#include <string>
//..boost library
#include <boost\algorithm\string.hpp>
#include <boost\range\algorithm\remove_if.hpp>


//.globals and declarations
/*
*
*
*/

class EditDistance
{
	//...member functions
	//...public interface
public:
	//.....overload operators
	//....constructors
	//.....default constructor
		EditDistance();
	//.....parameterized constructor
	//.....destructor
	//....operations
	//.....observers
		std::string getStringOne();
		std::string getStringTwo();
		int getStringOneLength();
		int getStringTwoLength();
		int getSubstitutionCost();
		int findMinimum(int a=0, int b=0, int c=0);
		virtual double calculateDistance() = 0;
		virtual double averageStringLengthSimilarity() = 0;
		virtual double maximizedStringLengthSimilarity() = 0;
		virtual double maximizedStringElementSimilarity() = 0;
	//.....mutators
		void setStringOne(std::string inString);
		void setStringTwo(std::string inString);
		void setSubstitutionCost(int inCost);
	//...private members
private:
	//....data members
		std::string stringOne;
		std::string stringTwo;
		int substitutionCost;
	//....functions
};

//non-member functions




//-------------------------------------------------------------------------------------------implementation---
EditDistance::EditDistance() {
	stringOne = "default";
	stringTwo = "default";
	substitutionCost = 2;
}

std::string EditDistance::getStringOne() { return stringOne; }

std::string EditDistance::getStringTwo() { return stringTwo; }

int EditDistance::getStringOneLength() { return stringOne.length(); }

int EditDistance::getStringTwoLength() { return stringTwo.length(); }

int EditDistance::getSubstitutionCost() { return substitutionCost; }

int EditDistance::findMinimum(int a, int b, int c) {
	return std::min(std::min(a, b), c);
}

void EditDistance::setStringOne(std::string inString) {
	stringOne = inString;
}

void EditDistance::setStringTwo(std::string inString) {
	stringTwo = inString;
}

void EditDistance::setSubstitutionCost(int inCost) {
	substitutionCost = inCost;
}
