#include "Utility.h"

enum class StringStatus {
	none,
	no,
	yes,
};

struct InfoString {
	StringStatus status = StringStatus::none;
	std::string string;
};

bool RecursiveDescentParser(InfoString& infoString, std::vector<InfoString>* rules, int32 depth, int32 section)
{
	std::vector<std::string> bags = TextToStringArray(infoString.string.data(), " bags");
	for (int32 i = 1; i < bags.size(); i++)
	{

		std::vector<std::string> words = TextToStringArray(bags[i].data(), " ");
		if (bags[i].find("shiny gold") != std::string::npos)
		{
			infoString.status = StringStatus::yes;
			return true;
		}
		else if (words[0] == "no ")
		{
			infoString.status = StringStatus::no;
			return false;
		}
		else
		{
			std::string combined = words[1] + words[2];
			for (InfoString& rule : *rules)
			{

				if (rule.string.find(combined) == 0)
					if (rule.status == StringStatus::yes || (rule.status != StringStatus::no && RecursiveDescentParser(rule, rules, ++depth, i)))
					{
						rule.status = StringStatus::yes;
						return true;
					}
			}
		}
	}
	infoString.status = StringStatus::no;
	return false;
}

int32 Day7Part1()
{
	printf("Day 7 part 1:\n");

	std::vector<std::string> text = FileToStringArray("Day7_Data.txt");
	for (std::string& string : text)
	{
		TextRemoval(string, " contain");
		TextRemoval(string, ",");
		TextRemoval(string, ".");

		std::string add = "bag ";
		for (int32 i = add.size(); i < string.size(); i++)
		{
			if (string.substr(i - add.size(), add.size()) == add)
				string.insert(i - 1, "s");
		}
		if (!((string.substr(string.size() - 4, 4) == "bags") || (string.substr(string.size() - 4, 4) == "ags.")))
			string.insert(string.size(), "s");
	}
	
	std::vector<InfoString> extraText;
	extraText.resize(text.size(), {});

	for (int32 i = 0; i < text.size(); i++)
		extraText[i].string = text[i];
	
	int32 result = 0;
	for (InfoString string : extraText)
		result += RecursiveDescentParser(string, &extraText, 0, 0);

	printf("Bags that hold Golden bags: %i\n\n", result);
	return result;
}


uint64 RecursiveDescentParser2(const std::string& string, std::vector<std::string>* rules)
{
	std::vector<std::string> bags = TextToStringArray(string.data(), " bags");
	uint64 result = 0;
	for (int32 i = 1; i < bags.size(); i++)
	{

		std::vector<std::string> words = TextToStringArray(bags[i].data(), " ");
		if (words[0] == "no ") 
			return 1;
		else
		{

			std::string combined = words[1] + words[2];
			for (const std::string& rule : *rules)
			{

				if (rule.find(combined) == 0)
				{
					uint64 test = (uint64)atoi(words[0].c_str());
					result +=  test * RecursiveDescentParser2(rule, rules);
				}
			}
		}
	}
	return result + 1;
}

int32 Day7Part2()
{
	printf("Day 7 part 2:\n");

	std::vector<std::string> text = FileToStringArray("Day7_Data.txt");
	for (std::string& string : text)
	{
		TextRemoval(string, " contain");
		TextRemoval(string, ",");
		TextRemoval(string, ".");


		std::string add = "bag ";
		for (int32 i = add.size(); i < string.size(); i++)
		{
			if (string.substr(i - add.size(), add.size()) == add)
				string.insert(i - 1, "s");
		}
		if (!((string.substr(string.size() - 4, 4) == "bags") || (string.substr(string.size() - 4, 4) == "ags.")))
			string.insert(string.size(), "s");
	}
	
	uint64 result = 0;
	for (const std::string& string : text)
	{
		if (string.find("shiny gold") == 0)
			result += RecursiveDescentParser2(string, &text) - 1;
	}

	printf("Amount of bags Golden Bags Hold: %u\n\n", result);
	return result;
}
