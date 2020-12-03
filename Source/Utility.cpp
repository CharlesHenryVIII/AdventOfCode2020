#include <cassert>
#include <vector>
#include <string>

#include "math.h"

struct FileText {
	const char* text;
	const long fileLength;
};

FileText ReadEntireFileAsString(const char* fileName)
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
	FileText text = { buffer, fileLength };
	return text;
}

std::vector<int> TextToIntArray(FileText data, const char lineEnd)
{
	std::vector<int> workingNums;
	std::vector<int> nums;
	workingNums.reserve(10);
	nums.reserve(16);

	for (int i = 0; data.text[i] != 0; i++)
	{

		//assert((data.text[i] - '0' >= 0  && data.text[i] - '0' <= '9') || data.text[i] == lineEnd);
		if (data.text[i] == lineEnd)
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
		else if (data.text[i] - '0' >= 0  && data.text[i] - '0' <= '9')
		{
			int value = data.text[i] - '0';
			workingNums.push_back(value);
		}
	}
	return nums;
}

std::vector<int> FileToIntArray(const char* fileName, const char lineEnd)
{
	return TextToIntArray(ReadEntireFileAsString(fileName), lineEnd);
}
