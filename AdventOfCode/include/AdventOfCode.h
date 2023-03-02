#pragma once

#include <vector>

struct Problem
{
	int number{};
	int (*function)() { nullptr };
	int answer{};
};

void createProblems(std::vector<Problem>& problems);
