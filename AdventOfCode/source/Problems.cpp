#include "AdventOfCode.h"

int year2015day01problem01();
int year2015day01problem02();
int year2015day02problem01();

void createProblems(std::vector<Problem>& problems)
{
	problems.push_back({ 20150101, year2015day01problem01, 74 });
	problems.push_back({ 20150102, year2015day01problem02, 1795 });
	problems.push_back({ 20150201, year2015day02problem01, 0 });
}
