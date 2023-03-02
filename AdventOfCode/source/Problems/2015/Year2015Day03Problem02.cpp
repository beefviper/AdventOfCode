/*
--- Part Two ---

The next year, to speed up the process, Santa creates a robot version of
himself, Robo-Santa, to deliver presents with him.

Santa and Robo-Santa start at the same location (delivering two presents to
the same starting house), then take turns moving based on instructions from
the elf, who is eggnoggedly reading from the same script as the previous
year.

This year, how many houses receive at least one present?

For example:

  - ^v delivers presents to 3 houses, because Santa goes north, and then
	Robo-Santa goes south.
  - ^>v< now delivers presents to 3 houses, and Santa and Robo-Santa end
	up back where they started.
  - ^v^v^v^v^v now delivers presents to 11 houses, with Santa going one
	direction and Robo-Santa going the other.

*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <utility>
#include <cstdlib>

int year2015day03problem02()
{
	std::string inputFileName{ "data/Year2015Day03Problem01.txt" };
	std::ifstream inputFile{ inputFileName };

	if (!inputFile)
	{
		std::cout << "Error opening file: " << inputFileName << std::endl;
		exit(EXIT_FAILURE);
	}

	std::string directionsString{};
	std::getline(inputFile, directionsString);

	std::istringstream directions{};
	directions.str(directionsString);

	std::map<std::pair<int, int>, int> houses;
	char direction{};

	int turn{};
	int x1{};
	int y1{};
	int x2{};
	int y2{};

	houses[{0, 0}] += 2;

	while (directions >> direction)
	{
		if (turn % 2 == 0)
		{
			if (direction == '>') { ++x1; }
			else if (direction == '<') { --x1; }
			else if (direction == '^') { ++y1; }
			else if (direction == 'v') { --y1; }

			houses[{x1, y1}] += 1;
		}
		else
		{
			if (direction == '>') { ++x2; }
			else if (direction == '<') { --x2; }
			else if (direction == '^') { ++y2; }
			else if (direction == 'v') { --y2; }

			houses[{x2, y2}] += 1;
		}

		++turn;
	}

	int housesWithPresents = static_cast<int>(houses.size());

	return housesWithPresents;
}
