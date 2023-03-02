/*
--- Part Two ---

Now, given the same instructions, find the position of the first character
that causes him to enter the basement (floor -1). The first character in
the instructions has position 1, the second character has position 2, and
so on.

For example:

  - ) causes him to enter the basement at character position 1.
  - ()()) causes him to enter the basement at character position 5.

What is the position of the character that causes Santa to first enter the
basement?
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

int year2015day01problem02()
{
	int floor{};
	int position{};
	char direction{};
	std::string inputFilename{ "data/year2015day01problem01.txt" };
	std::ifstream inputFile{ inputFilename };

	if (!inputFile)
	{
		std::cout << "error opening " << inputFilename << std::endl;
		exit(EXIT_FAILURE);
	}

	while (inputFile >> direction)
	{
		if (direction == '(')
		{
			++floor;
		}
		else if (direction == ')')
		{
			--floor;
		}

		++position;

		if (floor == -1)
		{
			break;
		}
	}

	inputFile.close();

	return position;
}
