#include "AdventOfCode.h"

#include <iostream>
#include <vector>

int main()
{
	std::vector<Problem> problems;
	createProblems(problems);

	for (auto& problem : problems)
	{
		std::cout << problem.number << ": " << problem.function() << std::endl;
	}

	return 0;
}
