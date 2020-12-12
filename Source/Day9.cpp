#include "Utility.h"

struct Value {
	int32 i = 0;
	int32 v= 0;
};

Value FindPatternBreak(const std::vector<int32>& nums, const int32 numOfComponents = 25)
{

	bool valueFound = false;
	for (int32 product = numOfComponents; product < nums.size(); product++)
	{
		valueFound = false;
		for (int32 a = product - numOfComponents; a < product && !valueFound; a++)
			for (int32 b = a + 1; b < product && !valueFound; b++)
				if (a != b)
					if (nums[a] + nums[b] == nums[product])
						valueFound = true;

		if (!valueFound)
			return { product, nums[product] };
	}
}

int32 Day9Part1()
{
	printf("Day 9 part 1:\n");
	int32 result = FindPatternBreak(FileToIntArray("Day9_Data.txt"), 25).v;

	printf("Answer: %i\n\n", result);
	return result;
}

int32 Day9Part2()
{
	printf("Day 9 part 2:\n");
	int32 result = 0;

	std::vector<int32> nums = FileToIntArray("Day9_Data.txt");
	Value value = FindPatternBreak(nums, 25);

	int32 val = 0;
	bool found = false;

	for (int32 i = 0; i < value.i && !found; i++)
	{
		val = 0;
		for (int32 o = i; o >= 0 && !found; o--)
		{
			val += nums[o];
			if (val == value.v)
			{
				int32 max = 0;
				int32 min = INT_MAX;
				for (int32 j = o; j < i; j++)
				{
					if (nums[j] > max)
						max = nums[j];
					if (nums[j] < min)
						min = nums[j];
				}
				result = min + max;
				found = true;
			}
		}
	}

	printf("Answer: %i\n\n", result);
	return result;
}
