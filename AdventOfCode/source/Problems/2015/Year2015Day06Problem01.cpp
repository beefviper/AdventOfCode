/*
--- Day 6: Probably a Fire Hazard ---

Because your neighbors keep defeating you in the holiday house decorating
contest year after year, you've decided to deploy one million lights in a
1000x1000 grid.

Furthermore, because you've been especially nice this year, Santa has
mailed you instructions on how to display the ideal lighting configuration.

Lights in your grid are numbered from 0 to 999 in each direction; the
lights at each corner are at 0,0, 0,999, 999,999, and 999,0. The
instructions include whether to turn on, turn off, or toggle various
inclusive ranges given as coordinate pairs. Each coordinate pair represents
opposite corners of a rectangle, inclusive; a coordinate pair like
0,0 through 2,2 therefore refers to 9 lights in a 3x3 square. The lights
all start turned off.

To defeat your neighbors this year, all you have to do is set up your
lights by doing the instructions Santa sent you in order.

For example:

  - turn on 0,0 through 999,999 would turn on (or leave on) every light.
  - toggle 0,0 through 999,0 would toggle the first line of 1000 lights,
	turning off the ones that were on, and turning on the ones that were off.
  - turn off 499,499 through 500,500 would turn off (or leave off) the
	middle four lights.

After following the instructions, how many lights are lit?
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <memory>

const int DIMENSION = 1000;

void lightsOn(bool* lights, int x1, int y1, int x2, int y2);
void lightsOff(bool* lights, int x1, int y1, int x2, int y2);
void lightsToggle(bool* lights, int x1, int y1, int x2, int y2);
int countLights(bool* lights);

int year2015day06problem01()
{
	std::string inputFileName{ "data/Year2015Day06Problem01.txt" };
	std::ifstream inputFile{ inputFileName };

	if (!inputFile)
	{
		std::cout << "Error opening file: " << inputFileName << std::endl;
		exit(EXIT_FAILURE);
	}

	bool* lights = new bool[DIMENSION * DIMENSION] {};
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

void lightsOn(bool* lights, int x1, int y1, int x2, int y2)
{
	for (int i = x1; i <= x2; ++i)
	{
		for (int j = y1; j <= y2; ++j)
		{
			lights[i * DIMENSION + j] = true;
		}
	}
}

void lightsOff(bool* lights, int x1, int y1, int x2, int y2)
{
	for (int i = x1; i <= x2; ++i)
	{
		for (int j = y1; j <= y2; ++j)
		{
			lights[i * DIMENSION + j] = false;
		}
	}
}

void lightsToggle(bool* lights, int x1, int y1, int x2, int y2)
{
	for (int i = x1; i <= x2; ++i)
	{
		for (int j = y1; j <= y2; ++j)
		{
			lights[i * DIMENSION + j] = !lights[i * DIMENSION + j];
		}
	}
}

int countLights(bool* lights)
{
	int totalLightsOn{};

	for (int i = 0; i < DIMENSION; ++i)
	{
		for (int j = 0; j < DIMENSION; ++j)
		{
			if (lights[i * DIMENSION + j] == true)
			{
				++totalLightsOn;
			}
		}
	}

	return totalLightsOn;
}
