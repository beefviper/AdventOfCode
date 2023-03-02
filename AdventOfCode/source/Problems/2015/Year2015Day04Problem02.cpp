/*
--- Part Two ---

Now find one that starts with six zeroes.
*/

#include "md5.h"

#include <iostream>
#include <fstream>
#include <string>

int year2015day04problem02()
{
	std::string inputFileName{ "data/Year2015Day04Problem01.txt" };
	std::ifstream inputFile{ inputFileName };

	if (!inputFile)
	{
		std::cout << "Error opening file: " << inputFileName << std::endl;
		exit(EXIT_FAILURE);
	}

	std::string key{};
	std::getline(inputFile, key);

	int count{ -1 };
	std::string hash{};

	do
	{
		++count;
		hash = md5(key + std::to_string(count));
	} while (hash.substr(0, 6) != "000000");

	return count;
}
