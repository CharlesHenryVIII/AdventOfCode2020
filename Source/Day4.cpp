#include "Utility.h"

int Day4Part1()
{
	printf("Day 4 Part 1:\n");

	std::vector<std::string> text = FileToStringArray("Day4_Data.txt", "\r\n\r\n");
	int32 valid = 0;

	for (std::string string : text)
	{
		//condition strings for use
		{
			int32 read = 0, write = 0;
			while (read < string.size())
			{

				if (string[read] == '\r' || string[read] == '\n')
				{
					if (read + 1 < string.size() && string[read + 1])
						read++;
					string[write] = ' ';
				}
				else
					string[write] = string[read];

				read++;
				write++;
			}
			string.resize(write);
		}

		int32 value = 0;
		bool cid = false;
		for (int32 i = 0; i < string.size(); i++)
		{
			std::string_view sv = string;
			if (sv.substr(i, 3) == "byr")
			{
				value++;
			}
			else if (sv.substr(i, 3) == "iyr")
			{
				value++;
			}
			else if (sv.substr(i, 3) == "eyr")
			{
				value++;
			}
			else if (sv.substr(i, 3) == "hgt")
			{
				value++;
			}
			else if (sv.substr(i, 3) == "hcl")
			{
				value++;
			}
			else if (sv.substr(i, 3) == "ecl")
			{
				value++;
			}
			else if (sv.substr(i, 3) == "pid")
			{
				value++;
			}
			else if (sv.substr(i, 3) == "cid")
			{
				value++;
				cid = true;
				//okay if missing
				//ignore
			}
			else
				assert(false);
			while (string[i] != ' ' && i < string.size())
				i++;
		}
			if ((value == 8 && cid) || (value == 7 && !cid))
				valid++;
	}
	printf("Valid passports: %i\n\n", valid);

	return valid;
}


int32 ValueCheckInString(const std::string& string, int32& i, int32 low, int32 high, bool incrimentIncrimenter)
{
	int32 j = NumberLengthInString(string, i);
	int32 integer = StringToInt(string, i, j);
	if (incrimentIncrimenter)
		i += j;

	if (j)
	{
		if (integer)
		{
			if (integer >= low && integer <= high)
				return true;
		}
	}
	return false;
}

int Day4Part2()
{
	printf("Day 4 Part 2:\n");

	std::vector<std::string> text = FileToStringArray("Day4_Data.txt", "\r\n\r\n");
	int32 valid = 0;

	for (std::string string : text)
	{
		//condition strings for use
		{
			int32 read = 0, write = 0;
			while (read < string.size())
			{

				if (string[read] == '\r' || string[read] == '\n')
				{
					if (read + 1 < string.size() && string[read + 1])
						read++;
					string[write] = ' ';
				}
				else
					string[write] = string[read];

				read++;
				write++;
			}
			string.resize(write);
		}

		//use strings
		int32 correctCheck = 0;
		for (int32 i = 0; i < string.size(); i++)
		{
			std::string_view sv = string;
			if (sv.substr(i, 3) == "byr")
			{
				i += 4;
				if (ValueCheckInString(string, i, 1920, 2002, true))
					correctCheck++;

			}
			else if (sv.substr(i, 3) == "iyr")
			{
				i += 4;
				if (ValueCheckInString(string, i, 2010, 2020, true))
					correctCheck++;

			}
			else if (sv.substr(i, 3) == "eyr")
			{

				i += 4;
				if (ValueCheckInString(string, i, 2020, 2030, true))
					correctCheck++;
			}
			else if (sv.substr(i, 3) == "hgt")
			{
				i += 4;
				int32 heightLength = NumberLengthInString(string, i);
				int32 height = StringToInt(string, i, heightLength);
				i += heightLength;

				if (string[i] == 'c' && string[i + 1] == 'm')
				{
					if (height >= 150 && height <= 193)
						correctCheck++;
				}
				else if (string[i] == 'i' && string[i + 1] == 'n')
				{
					if (height >= 59 && height <= 76)
						correctCheck++;
				}
			}
			else if (sv.substr(i, 3) == "hcl")
			{
				i += 4;

				if (string[i] == '#')
				{
					i++;
					int32 start = i;
					while (string[i] != ' ' && ((string[i] >= '0' && string[i] <= '9') || (string[i] >= 'a' && string[i] <= 'f')))
						i++;
					if (i - start == 6)
						correctCheck++;

				}
			}
			else if (sv.substr(i, 3) == "ecl")
			{
				i += 4;
				const char* colors[] = { "amb", "blu", "brn", "gry", "grn", "hzl", "oth" };
				
				for (int32 j = 0; j < sizeof(colors) / sizeof(colors[0]); j++)
				{
					if (string.substr(i, 3) == colors[j])
					{

						correctCheck++;
						i += 3;
						break;
					}
				}
			}
			else if (sv.substr(i, 3) == "pid")
			{
				i += 4;

				int32 j = 0;
				while (string[i + j] >= '0' && string[i + j] <= '9')
					j++;

				if (j == 9)
					correctCheck++;
				i += j;
			}
			else if (sv.substr(i, 3) == "cid")
			{
				i += 4;
				//okay if missing
				//ignore
			}
			else
				assert(false);
			while (string[i] != ' ' && i < string.size())
				i++;
		}
			if (correctCheck == 7 )
				valid++;
	}
	printf("Valid passports: %i\n\n", valid);

	return valid;
}
