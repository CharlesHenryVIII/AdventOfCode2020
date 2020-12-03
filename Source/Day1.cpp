#include "Utility.h"

int Day1Part1()
{
	printf("Day 1 Part 1: \n");

	std::vector<int> values = FileToIntArray("Day1_Data.txt", '\n');

	for (int i = 0; i < values.size(); i++)
	{
		for (int j = i + 1; j < values.size(); j++)
		{
			if (values[i] + values[j] == 2020)
			{

				printf("%i + %i = 2020\n", values[i], values[j]);
				printf("Multiplied together you get: %i\n\n", (values[i] * values[j]));
				return values[i] + values[j];
			}
		}
	}

	printf("No value was found that added to 2020\n\n");
	return 0;
}

int Day1Part2()
{
	printf("Day 1 Part 2: \n");

	std::vector<int> values = FileToIntArray("Day1_Data.txt", '\n');

	for (int i = 0; i < values.size(); i++)
	{
		for (int j = i + 1; j < values.size(); j++)
		{
			for (int k = j + 1; k < values.size(); k++)
			{
				if (values[i] + values[j] + values[k] == 2020)
				{

					printf("%i + %i + %i = 2020\n", values[i], values[j], values[k]);
					printf("Multiplied together you get: %i\n\n", (values[i] * values[j] * values[k]));
					return values[i] * values[j] * values[k];
				}

			}
		}
	}

	printf("No value was found that added to 2020\n\n");
	return 0;
}
