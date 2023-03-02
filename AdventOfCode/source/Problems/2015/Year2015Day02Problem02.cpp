/*
--- Part Two ---

The elves are also running low on ribbon. Ribbon is all the same width, so
they only have to worry about the length they need to order, which they
would again like to be exact.

The ribbon required to wrap a present is the shortest distance around its
sides, or the smallest perimeter of any one face. Each present also
requires a bow made out of ribbon as well; the feet of ribbon required for
the perfect bow is equal to the cubic feet of volume of the present. Don't
ask how they tie the bow, though; they'll never tell.

For example:

  - A present with dimensions 2x3x4 requires 2+2+3+3 = 10 feet of ribbon
    to wrap the present plus 2*3*4 = 24 feet of ribbon for the bow, for a
    total of 34 feet.
  - A present with dimensions 1x1x10 requires 1+1+1+1 = 4 feet of ribbon
    to wrap the present plus 1*1*10 = 10 feet of ribbon for the bow, for a
    total of 14 feet.

How many total feet of ribbon should they order?
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cstdlib>

int year2015day02problem02()
{
    std::string inputFileName{ "data/Year2015Day02Problem01.txt" };
    std::ifstream inputFile{ inputFileName };

    if (!inputFile)
    {
        std::cout << "Error opening file: " << inputFileName << std::endl;
        exit(EXIT_FAILURE);
    }

    int length{};
    int width{};
    int height{};
    char delimiter{};
    int totalRibbon{};

    std::string dimensionsString{};
    std::istringstream dimensions{};

    while (std::getline(inputFile, dimensionsString))
    {
        dimensions.clear();
        dimensions.str(dimensionsString);

        dimensions >> length >> delimiter >> width >> delimiter >> height;

        std::vector sides{ length, width, height };
        std::ranges::sort(sides);

        int volume = length * width * height;
        
        totalRibbon += 2 * (sides.at(0) + sides.at(1)) + volume;
    }

    return totalRibbon;
}
