#include "AdventOfCode.h"

int year2015day01problem01();
int year2015day01problem02();
int year2015day02problem01();
int year2015day02problem02();
int year2015day03problem01();
int year2015day03problem02();

void createProblems(std::vector<Problem>& problems)
{
	problems.push_back({ 20150101, year2015day01problem01, 74 });
	problems.push_back({ 20150102, year2015day01problem02, 1795 });
	problems.push_back({ 20150201, year2015day02problem01, 1598415 });
	problems.push_back({ 20150202, year2015day02problem02, 3812909 });
	problems.push_back({ 20150301, year2015day03problem01, 2565 });
	problems.push_back({ 20150302, year2015day03problem02, 2639 });
}
