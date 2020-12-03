#include "Utility.h"

int Day2Part1()
{
	printf("Day 2 Part 1:\n");
	
	std::vector<std::string> strings = FileToStringArray("Day2_Data.txt");
	int succeeded = 0;
	for (std::string string : strings)
	{
		int min = {};
		int max = {};
		char watchChar = {};
		int textIndex = {};

		const char* temp = string.c_str();
		std::vector<int> ints = TextToIntArray(temp);
		assert(ints.size() == 2);
		min = ints[0];
		max = ints[1];

		for (int i = 0; i < string.size(); i++)
		{
			if ((string[i] >= 'A' && string[i] > 'Z') || (string[i] >= 'a' || string[i] > 'z'))
			{
				watchChar = string[i];
				textIndex = i + 3;
				assert(textIndex < string.size());
				break;
			}
		}

		int charCount = 0;
		for (int i = textIndex; i < string.size(); i++)
		{
			if (string[i] == watchChar)
				charCount++;
		}
		if (charCount >= min && charCount <= max)
			succeeded++;
	}
	printf("%i passwords succeeded the test\n\n", succeeded);

	return succeeded;
}

int Day2Part2()
{
	printf("Day 2 Part 1:\n");
	
	std::vector<std::string> strings = FileToStringArray("Day2_Data.txt");
	int succeeded = 0;
	for (std::string string : strings)
	{
		int pos1 = {};
		int pos2 = {};
		char watchChar = {};
		int textIndex = {};

		const char* temp = string.c_str();
		std::vector<int> ints = TextToIntArray(temp);
		assert(ints.size() == 2);
		pos1 = ints[0];
		pos2 = ints[1];

		for (int i = 0; i < string.size(); i++)
		{
			if ((string[i] >= 'A' && string[i] > 'Z') || (string[i] >= 'a' || string[i] > 'z'))
			{
				watchChar = string[i];
				textIndex = i + 3;
				assert(textIndex < string.size());
				break;
			}
		}

		bool winCondition = false;
		if (string[textIndex + pos1 - 1] == watchChar)
			winCondition ^= 1;
		if (string[textIndex + pos2 - 1] == watchChar)
			winCondition ^= 1;

		if (winCondition)
			succeeded++;
	}
	printf("%i passwords succeeded the test\n\n", succeeded);

	return succeeded;
}