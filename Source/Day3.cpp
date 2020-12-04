#include "Utility.h"

int Day3Part1()
{
	printf("Day 3 Part 1:\n");

	std::vector<std::string> text = FileToStringArray("Day3_Data.txt");
	Vectori position = {};
	Vectori slope = { 3, 1 };

	int trees = 0;
	while (position.y < text.size())
	{
		if (text[position.y][position.x % text[0].size()] == '#')
			trees++;
		position += slope;
	}
	printf("Trees Encountered: %i\n\n", trees);

	return trees;
}

int Day3Part2()
{
	printf("Day 3 Part 2:\n");

	std::vector<std::string> text = FileToStringArray("Day3_Data.txt");

	int32 trees = 0;
	Vectori position = {};
	uint32 treesMultiplied = 1;
	Vectori slopeVectors[] = {
		{1, 1},
		{3, 1},
		{5, 1},
		{7, 1},
		{1, 2},
	};

	for (int32 i = 0; i < sizeof(slopeVectors) / sizeof(slopeVectors[0]); i++)
	{
		trees = 0;
		position = {};
		while (position.y < text.size())
		{
			if (text[position.y][position.x % text[0].size()] == '#')
				trees++;
			position += slopeVectors[i];
		}
		printf("Trees encountered for slope {%i, %i}: %i\n", slopeVectors[i].x, slopeVectors[i].y, trees);
		treesMultiplied *= trees;
	}
	
	printf("Amount of trees multiplied together: %u\n\n", treesMultiplied);

	return treesMultiplied;
}