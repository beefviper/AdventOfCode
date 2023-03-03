/*
--- Day 3: Perfectly Spherical Houses in a Vacuum ---

Santa is delivering presents to an infinite two-dimensional grid of houses.

He begins by delivering a present to the house at his starting location,
and then an elf at the North Pole calls him via radio and tells him where
to move next. Moves are always exactly one house to the north (^), south (v
), east (>), or west (<). After each move, he delivers another present to
the house at his new location.

However, the elf back at the north pole has had a little too much eggnog,
and so his directions are a little off, and Santa ends up visiting some
houses more than once. How many houses receive at least one present?

For example:

  - > delivers presents to 2 houses: one at the starting location, and one
    to the east.
  - ^>v< delivers presents to 4 houses in a square, including twice to the
    house at his starting/ending location.
  - ^v^v^v^v^v delivers a bunch of presents to some very lucky children at
    only 2 houses.

*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <utility>
#include <cstdlib>

int year2015day03problem01()
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
    int x{};
    int y{};

    houses[{0, 0}] = 1;

    while (directions >> direction)
    {
        if (direction == '>') { ++x; }
        else if (direction == '<') { --x; }
        else if (direction == '^') { ++y; }
        else if (direction == 'v') { --y; }

        houses[{x, y}] += 1;
    }

    int housesWithPresents = static_cast<int>(houses.size());

    inputFile.close();

    return housesWithPresents;
}
