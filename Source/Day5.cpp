#include "Utility.h"

int Day5Part1()
{
	printf("Day 5 Part 1:\n");
	std::vector<std::string> longTextPhrase = FileToStringArray("Day5_Data.txt");
	
	int32 highestID = 0;
	const int32 rows = 128;
	const int32 cols = 8;
	for (std::string string : longTextPhrase)
	{
		int32 upperRows = rows - 1;
		int32 lowerRows = 0;
		int32 upperCols = cols - 1;
		int32 lowerCols = 0;
		for (int32 i = 0; i < string.size(); i++)
		{
			int32 rowDifference = (upperRows - lowerRows + 1) / 2;
			int32 colDifference = (upperCols - lowerCols + 1) / 2;
			if (string[i] == 'F')
				upperRows -= rowDifference;
			else if (string[i] == 'B')
				lowerRows += rowDifference;
			else if (string[i] == 'L')
				upperCols -= colDifference;
			else if (string[i] == 'R')
				lowerCols += colDifference;
		}
		assert(upperRows == lowerRows);
		assert(upperCols == lowerCols);
		int32 temp = upperRows * 8 + upperCols;
		if (temp > highestID)
			highestID = temp;
	}

	printf("Highest ID: %i\n\n", highestID);
	return highestID;
}

int Day5Part2()
{
	printf("Day 5 Part 2:\n");

	std::vector<std::string> longTextPhrase = FileToStringArray("Day5_Data.txt");
	
	const int32 rows = 128;
	const int32 cols = 8;
	bool seats[rows][cols] = {};
	for (std::string string : longTextPhrase)
	{

		int32 upperRows = rows - 1;
		int32 lowerRows = 0;
		int32 upperCols = cols - 1;
		int32 lowerCols = 0;
		for (int32 i = 0; i < string.size(); i++)
		{

			int32 rowDifference = (upperRows - lowerRows + 1) / 2;
			int32 colDifference = (upperCols - lowerCols + 1) / 2;
			if (string[i] == 'F')
				upperRows -= rowDifference;
			else if (string[i] == 'B')
				lowerRows += rowDifference;
			else if (string[i] == 'L')
				upperCols -= colDifference;
			else if (string[i] == 'R')
				lowerCols += colDifference;
		}
		assert(upperRows == lowerRows);
		assert(upperCols == lowerCols);

		seats[upperRows][upperCols] = true;
	}

#if 0
	printf("    /\\\n");
	printf("   /  \\\n");
	printf("  /    \\\n");
	printf(" /      \\\n");
	printf("/        \\\n");
	for (int32 i = 0; i < rows; i++)
	{
		printf("|");
		for (int32 j = 0; j < cols; j++)
		{
			if (seats[i][j])
				printf("#");
			else
				printf(" ");
		}
		printf("|\n");
	}
	return 0;
#else


	int32 seatID = 0;
	for (int32 i = 0; i < rows; i++)
	{
		for (int32 j = 0; j < cols; j++)
		{
			if (seats[i][j - 1] && !seats[i][j] && seats[i][j + 1])
			{
				seatID = i * 8 + j;
				printf("ID of seat: %i\n\n", seatID);
			}
		}
	}
	return seatID;
#endif

	//printf("Highest ID:\n\n", highestID);
}
