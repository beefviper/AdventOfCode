#include "AdventOfCode.h"

int year2015day01problem01();
int year2015day01problem02();
int year2015day02problem01();
int year2015day02problem02();
int year2015day03problem01();
int year2015day03problem02();
int year2015day04problem01();
int year2015day04problem02();
int year2015day05problem01();
int year2015day05problem02();
int year2015day06problem01();
int year2015day06problem02();
int year2015day07problem01();

void createProblems(std::vector<Problem>& problems)
{
	problems.push_back({ 20150101, year2015day01problem01, 74 });
	problems.push_back({ 20150102, year2015day01problem02, 1795 });
	problems.push_back({ 20150201, year2015day02problem01, 1598415 });
	problems.push_back({ 20150202, year2015day02problem02, 3812909 });
	problems.push_back({ 20150301, year2015day03problem01, 2565 });
	problems.push_back({ 20150302, year2015day03problem02, 2639 });
	problems.push_back({ 20150401, year2015day04problem01, 117946 });
	problems.push_back({ 20150402, year2015day04problem02, 3938038 });
	problems.push_back({ 20150501, year2015day05problem01, 236 });
	problems.push_back({ 20150502, year2015day05problem02, 51 });
	problems.push_back({ 20150601, year2015day06problem01, 400410 });
	problems.push_back({ 20150602, year2015day06problem02, 15343601 });
	problems.push_back({ 20150701, year2015day07problem01, 0 });
}
