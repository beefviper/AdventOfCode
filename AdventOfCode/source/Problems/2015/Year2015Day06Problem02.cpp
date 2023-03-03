/*
--- Part Two ---

You just finish implementing your winning light pattern when you realize
you mistranslated Santa's message from Ancient Nordic Elvish.

The light grid you bought actually has individual brightness controls; each
light can have a brightness of zero or more. The lights all start at zero.

The phrase turn on actually means that you should increase the brightness
of those lights by 1.

The phrase turn off actually means that you should decrease the brightness
of those lights by 1, to a minimum of zero.

The phrase toggle actually means that you should increase the brightness of
those lights by 2.

What is the total brightness of all lights combined after following Santa's
instructions?

For example:

  - turn on 0,0 through 0,0 would increase the total brightness by 1.
  - toggle 0,0 through 999,999 would increase the total brightness by
    2000000.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <memory>

const int DIMENSION = 1000;

void lightsOn(int* lights, int x1, int y1, int x2, int y2);
void lightsOff(int* lights, int x1, int y1, int x2, int y2);
void lightsToggle(int* lights, int x1, int y1, int x2, int y2);
int countLights(int* lights);

int year2015day06problem02()
{
	std::string inputFileName{ "data/Year2015Day06Problem01.txt" };
	std::ifstream inputFile{ inputFileName };

	if (!inputFile)
	{
		std::cout << "Error opening file: " << inputFileName << std::endl;
		exit(EXIT_FAILURE);
	}

	int* lights = new int[DIMENSION * DIMENSION] {};
	std::string inputString{};
	std::istringstream input{};
	std::string command;

	std::getline(inputFile, inputString);
	input.clear();
	input.str(inputString);

	while (inputString != "")
	{
		int x1{};
		int y1{};
		int x2{};
		int y2{};
		char delim{};
		std::string skip{};

		input >> command;

		if (command == "turn")
		{
			input >> command;
		}

		input >> x1 >> delim >> y1 >> skip >> x2 >> delim >> y2;

		if (command == "on")
		{
			lightsOn(lights, x1, y1, x2, y2);
		}
		if (command == "off")
		{
			lightsOff(lights, x1, y1, x2, y2);
		}
		if (command == "toggle")
		{
			lightsToggle(lights, x1, y1, x2, y2);
		}

		std::getline(inputFile, inputString);
		input.clear();
		input.str(inputString);
	}

	int totalLightsOn = countLights(lights);

	delete[] lights;
	inputFile.close();

	return totalLightsOn;
}

void lightsOn(int* lights, int x1, int y1, int x2, int y2)
{
	for (int i = x1; i <= x2; ++i)
	{
		for (int j = y1; j <= y2; ++j)
		{
			lights[i * DIMENSION + j] += 1;
		}
	}
}

void lightsOff(int* lights, int x1, int y1, int x2, int y2)
{
	for (int i = x1; i <= x2; ++i)
	{
		for (int j = y1; j <= y2; ++j)
		{

			lights[i * DIMENSION + j] -= 1;

			if (lights[i * DIMENSION + j] < 0)
			{
				lights[i * DIMENSION + j] = 0;
			}
		}
	}
}

void lightsToggle(int* lights, int x1, int y1, int x2, int y2)
{
	for (int i = x1; i <= x2; ++i)
	{
		for (int j = y1; j <= y2; ++j)
		{
			lights[i * DIMENSION + j] += 2;
		}
	}
}

int countLights(int* lights)
{
	int totalLightsOn{};

	for (int i = 0; i < DIMENSION; ++i)
	{
		for (int j = 0; j < DIMENSION; ++j)
		{
			totalLightsOn += lights[i * DIMENSION + j];
		}
	}

	return totalLightsOn;
}
