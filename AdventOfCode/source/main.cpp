#include "AdventOfCode.h"

#include <iostream>
#include <vector>

int main()
{
	std::vector<Problem> problems;
	createProblems(problems);

	for (auto& problem : problems)
	{
		if (problem.answer != 0)
		{
			std::cout << problem.number << ": " << problem.answer << std::endl;
		}
		else
		{
			std::cout << problem.number << ": " << problem.function() << std::endl;
		}
	}

	return 0;
}
