/*
--- Day 5: Doesn't He Have Intern-Elves For This? ---

Santa needs help figuring out which strings in his text file are naughty or
nice.

A nice string is one with all of the following properties:

  - It contains at least three vowels (aeiou only), like aei, xazegov, or
    aeiouaeiouaeiou.
  - It contains at least one letter that appears twice in a row, like xx,
    abcdde (dd), or aabbccdd (aa, bb, cc, or dd).
  - It does not contain the strings ab, cd, pq, or xy, even if they are
    part of one of the other requirements.

For example:

  - ugknbfddgicrmopn is nice because it has at least three vowels (
    u...i...o...), a double letter (...dd...), and none of the disallowed
    substrings.
  - aaa is nice because it has at least three vowels and a double letter,
    even though the letters used by different rules overlap.
  - jchzalrnumimnmhp is naughty because it has no double letter.
  - haegwjzuvuyypxyu is naughty because it contains the string xy.
  - dvszwmarrgswjxmb is naughty because it contains only one vowel.

How many strings are nice?
*/

#include <iostream>
#include <string>
#include <fstream>

bool containsAtLeastThreeVowels(std::string inputString);
bool containsOneLetterTwiceInARow(std::string inputString);
bool doesNotContainBannedPair(std::string inputString);

int year2015day05problem01()
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

        nice = containsAtLeastThreeVowels(inputString) &&
            containsOneLetterTwiceInARow(inputString) &&
            doesNotContainBannedPair(inputString);

        if (nice)
        {
            ++niceWords;
        }

        std::getline(inputFile, inputString);
    }

    return niceWords;
}

bool containsAtLeastThreeVowels(std::string inputString)
{
    bool result{ false };
    std::string vowels{ "aeiou" };
    int count{};
    size_t position{};

    position = inputString.find_first_of(vowels);
    while (position != std::string::npos)
    {
        ++count;
        position = inputString.find_first_of(vowels, position + 1);
    }

    if (count >= 3)
    {
        result = true;
    }

    return result;
}

bool containsOneLetterTwiceInARow(std::string inputString)
{
    bool result{ false };

    for (auto iter = inputString.begin(); iter < inputString.end() - 1; ++iter)
    {
        if (*iter == *(iter + 1))
        {
            result = true;
        }
    }

    return result;
}

bool doesNotContainBannedPair(std::string inputString)
{
    bool result{ true };
    std::size_t found{};

    found = inputString.find("ab");
    if (found != std::string::npos)
    {
        result = false;
    }

    found = inputString.find("cd");
    if (found != std::string::npos)
    {
        result = false;
    }

    found = inputString.find("pq");
    if (found != std::string::npos)
    {
        result = false;
    }

    found = inputString.find("xy");
    if (found != std::string::npos)
    {
        result = false;
    }

    return result;
}
