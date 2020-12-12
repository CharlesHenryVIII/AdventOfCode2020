#include <stdio.h>

int Day1Part1();
int Day1Part2();
int Day2Part1();
int Day2Part2();
int Day3Part1();
int Day3Part2();
int Day4Part1();
int Day4Part2();
int Day5Part1();
int Day5Part2();
int Day6Part1();
int Day6Part2();
int Day7Part1();
int Day7Part2();
int Day8Part1();
int Day8Part2();

struct FunctionCheckData {
	int program = 0;
	int answer = 0;
};
FunctionCheckData programs[] = {
	{ Day1Part1(), 326211 }, 
	{ Day1Part2(), 131347190 }, 
	{ Day2Part1(), 524 }, 
	{ Day2Part2(), 485 }, 
	{ Day3Part1(), 232 }, 
	{ Day3Part2(), 3952291680 }, 
	{ Day4Part1(), 256 }, 
	{ Day4Part2(), 198 }, 
	{ Day5Part1(), 913 }, 
	{ Day5Part2(), 717 }, 
	{ Day6Part1(), 6662 }, 
	{ Day6Part2(), 3382 }, 
	{ Day7Part1(), 335 }, 
	{ Day7Part2(), 2431 }, 
	{ Day8Part1(), 2051 }, 
	{ Day8Part2(), 2304 }, 
};

int main()
{
	for (int i = 0; i < (sizeof(programs) / sizeof(programs[0])); i++)
	{
		if (programs[i].program == programs[i].answer)
			printf("Day %i, Part %i pass\n", i / 2 + 1, (i % 2) + 1);
		else
			printf("Day %i, Part %i fail\n", i / 2 + 1, (i % 2) + 1);
	}
	return 0;
}
