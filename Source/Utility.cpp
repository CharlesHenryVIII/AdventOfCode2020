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

std::vector<std::string> TextToStringArray(const char* text, const char* lineEnd)
{
	assert(lineEnd);
	assert(text);

	//int32 lineEndLength = 0;
	//while (lineEnd[lineEndLength + 1] != 0)
	//	lineEndLength++;

	std::string_view sv = text;
	std::vector<std::string> result;

	int tokenLength = 0;
	for (int i = 0; text[i] != 0; i++)
	{
		bool isLineEnd = false;
		if (text[i] == lineEnd[0] || text[i + 1] == 0)
		{
			int32 incrimenter = 0;
			while (text[i + incrimenter] == lineEnd[incrimenter])
			{

				if (lineEnd[incrimenter + 1] == 0)
				{
					isLineEnd = true;
					break;
				}
				incrimenter++;
			}
			if (tokenLength && (isLineEnd || text[i + 1] == 0))
			{

				std::string token;
				token = sv.substr(i - tokenLength, tokenLength);
				result.push_back(token);
				tokenLength = 0;
				i += incrimenter;
				isLineEnd = true;
			}
		}
		if (!isLineEnd)
			tokenLength++;
		
		if (i == 22201)
			isLineEnd = 10;
	}
	assert(tokenLength == 0);
	return result;
}

std::vector<std::string> FileToStringArray(const char* fileName)
{
	return TextToStringArray(ReadEntireFileAsString(fileName));
}

std::vector<std::string> FileToStringArray(const char* fileName, const char* lineEnd)
{
	return TextToStringArray(ReadEntireFileAsString(fileName), lineEnd);
}

std::vector<int> FileToIntArray(const char* fileName, const char lineEnd)
{
	return TextToIntArray(ReadEntireFileAsString(fileName), lineEnd);
}

int32 NumberLengthInString(const std::string& string, int32& i)
{

	int32 j = 0;
	while (string[i + j] >= '0' && string[i + j] <= '9')
		j++;
	return j;
}

int32 StringToInt(const std::string& string, int32 i, int32 length)
{
	return atoi(string.substr(i, length).c_str());
}

int32 StringToInt(const std::string& string, int32 i)
{
	return StringToInt(string, i, NumberLengthInString(string, i));
}
