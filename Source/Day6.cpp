#include "Utility.h"


int32 Day6Part1()
{
	printf("Day 6 Part 1:\n");

	std::vector<std::string> text = FileToStringArray("Day6_Data.txt", "\r\n\r\n");

	int32 count = 0;
	const int32 arrLength = 'z' - 'a' + 1;
	bool arr[arrLength] = {};
	for (std::string string : text)
	{
		memset(arr, false, arrLength);
		for (char character : string)
		{
			if ((character >= 'a' && character <= 'z'))
			{
				if (!(arr[character - 'a']))
				{
					count++;
					arr[character - 'a'] = true;
				}
			}
		}
	}

	printf("Sum: %i\n\n", count);
	return count;
}

int32 Day6Part2()
{
	printf("Day 6 Part 1:\n");

	std::vector<std::string> text = FileToStringArray("Day6_Data.txt", "\r\n\r\n");

	int32 count = 0;
	const int32 size = 'z' - 'a' + 1;
	int32 questions[size] = {};
	int32 persons = 1;
	for (std::string string : text)
	{
		memset(questions, 0, (size * sizeof(questions[0])));
		persons = 1;
		for (char character : string)
		{
			if (character == '\r')
				continue;
			else if (character == '\n')
				persons++;
			else if ((character >= 'a' && character <= 'z'))
				questions[character - 'a']++;
		}

		for (int32 i = 0; i < size; i++)
			if (questions[i] == persons)
				count++;
	}

	printf("Sum: %i\n\n", count);
	return count;
}
