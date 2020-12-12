#include <stdio.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

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
int Day9Part1();
int Day9Part2();

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
	{ Day9Part1(), 217430975 }, 
	{ Day9Part2(), 28509180 }, 
};

int main()
{

	const int size = sizeof(programs) / sizeof(programs[0]);
	bool passed[size] = {};
	int passrate = 0;
	for (int i = 0; i < size; i++)
	{
		if (programs[i].program == programs[i].answer)
		{
			passed[i] = true;
			passrate++;
		}
	}

	if (passrate == size)
		printf(ANSI_COLOR_GREEN "%i OF %i PASSED\n" ANSI_COLOR_RESET, passrate, size);
	else
	{
		printf(ANSI_COLOR_YELLOW "%i OF %i PASSED\n" ANSI_COLOR_RESET, passrate, size);
		for (int i = 0; i < size; i++)
		{
			if (!passed[i])
				printf(ANSI_COLOR_RED "DAY %i, PART %i FAIL\n" ANSI_COLOR_RESET, i / 2 + 1, (i % 2) + 1);
		}
	}

	return 0;
}
