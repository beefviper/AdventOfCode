/*
--- Part Two ---

Realizing the error of his ways, Santa has switched to a better model of
determining whether a string is naughty or nice. None of the old rules
apply, as they are all clearly ridiculous.

Now, a nice string is one with all of the following properties:

  - It contains a pair of any two letters that appears at least twice in
	the string without overlapping, like xyxy (xy) or aabcdefgaa (aa), but
	not like aaa (aa, but it overlaps).
  - It contains at least one letter which repeats with exactly one letter
	between them, like xyx, abcdefeghi (efe), or even aaa.

For example:

  - qjhvhtzxzqqjkmpb is nice because is has a pair that appears twice (qj)
	and a letter that repeats with exactly one letter between them (zxz).
  - xxyxx is nice because it has a pair that appears twice and a letter
	that repeats with one between, even though the letters used by each
	rule overlap.
  - uurcxstgmygtbstg is naughty because it has a pair (tg) but no repeat
	with a single letter between them.
  - ieodomkazucvgmuy is naughty because it has a repeating letter with one
	between (odo), but no pair that appears twice.

How many strings are nice under these new rules?
*/

#include <iostream>
#include <string>
#include <fstream>

bool containsPairTwice(std::string inputString);
bool containsReapeatLetterOneSpaceApart(std::string inputString);

int year2015day05problem02()
{
	std::string inputFileName{ "data/Year2015Day05Problem01.txt" };
	std::ifstream inputFile{ inputFileName };

	if (!inputFile)
	{
		std::cout << "Error opening file: " << inputFileName << std::endl;
		exit(EXIT_FAILURE);
	}

	int niceWords{};
	std::string inputString{};
	std::getline(inputFile, inputString);

	while (inputString != "")
	{
		bool nice{ false };

		nice = containsPairTwice(inputString) &&
			containsReapeatLetterOneSpaceApart(inputString);

		if (nice)
		{
			++niceWords;
		}

		std::getline(inputFile, inputString);
	}

	inputFile.close();

	return niceWords;
}

bool containsPairTwice(std::string inputString)
{
	bool result{ false };

	for (auto iter = inputString.begin(); iter < inputString.end() - 3; ++iter)
	{
		for (auto iter2 = iter + 2; iter2 < inputString.end() - 1; ++iter2)
		{
			if ((*iter == *iter2) && (*(iter + 1) == *(iter2 + 1)))
			{
				result = true;
			}
		}
	}

	return result;
}

bool containsReapeatLetterOneSpaceApart(std::string inputString)
{
	bool result{ false };

	for (auto iter = inputString.begin(); iter < inputString.end() - 2; ++iter)
	{
		if (*iter == *(iter + 2))
		{
			result = true;
		}
	}

	return result;
}
