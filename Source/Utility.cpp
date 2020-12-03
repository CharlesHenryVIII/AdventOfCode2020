#include <vector>
#include <string_view>

#include "math.h"

#include "Utility.h"

const char* ReadEntireFileAsString(const char* fileName)
{
	FILE* file;
	file = fopen(fileName, "rb");
	fseek(file, 0, SEEK_END);
	const long fileLength = ftell(file);
	fseek(file, 0, SEEK_SET);
	char* buffer = new char[fileLength + 1];
	fread(buffer, 1, fileLength, file);
	fclose(file);
	buffer[fileLength] = 0;
	return buffer;
}

std::vector<int> TextToIntArray(const char* text, const char lineEnd)
{
	std::vector<int> workingNums;
	std::vector<int> nums;
	workingNums.reserve(10);
	nums.reserve(16);

	for (int i = 0; text[i] != 0; i++)
	{

		//assert((data.text[i] - '0' >= 0  && data.text[i] - '0' <= '9') || data.text[i] == lineEnd);
		if (text[i] - '0' >= 0  && text[i] - '0' <= '9')
		{
			int value = text[i] - '0';
			workingNums.push_back(value);
		}
		else if (text[i] == lineEnd)
		{
			int value = 0;
			for (int j = 0; j < workingNums.size(); j++)
			{
				value += (workingNums[j] * (int)pow(10, workingNums.size() - 1 - j));
			}
			assert(value); //should not occurr
			if (value)
			{
				nums.push_back(value);
				workingNums.clear();
			}
		}
	}
	delete text;
	return nums;
}

std::vector<int> TextToIntArray(const char* text)
{
	std::vector<int> workingNums;
	std::vector<int> nums;
	workingNums.reserve(10);
	nums.reserve(2);

	for (int i = 0; text[i] != 0; i++)
	{

		if (text[i] >= '0' && text[i] <= '9')
		{

			int value = text[i] - '0';
			workingNums.push_back(value);
		}
		else
		{
			if (workingNums.size())
			{
				
				int value = 0;
				for (int j = 0; j < workingNums.size(); j++)
				{
					value += (workingNums[j] * (int)pow(10, workingNums.size() - 1 - j));
				}

				nums.push_back(value);
				workingNums.clear();
			}
		}
	}
	return nums;
}

std::vector<std::string> TextToStringArray(const char* text)
{
	std::string_view sv = text;
	std::vector<std::string> result;

	int tokenLength = 0;
	for (int i = 0; text[i - 1] != 0; i++)
	{
		if (text[i] >= ' ' && text[i] <= '~')
		{
			tokenLength++;
		}
		else
		{
			if (tokenLength)
			{

				std::string token;
				token = sv.substr(i - tokenLength, tokenLength);
				result.push_back(token);
				tokenLength = 0;
			}
		}
	}
	assert(tokenLength == 0);
	return result;
}

std::vector<std::string> FileToStringArray(const char* fileName)
{
	return TextToStringArray(ReadEntireFileAsString(fileName));
}

std::vector<int> FileToIntArray(const char* fileName, const char lineEnd)
{
	return TextToIntArray(ReadEntireFileAsString(fileName), lineEnd);
}
