#include "Utility.h"

struct Instruction {
	std::string instruction;
	const int32 argument;
	bool executed = false;
};

int32 Day8Part1()
{
	printf("Day 8 part 1:\n");
	int32 result = 0;

	std::vector<Instruction> instructions;
	{
		std::vector<std::string> text = FileToStringArray("Day8_Data.txt");
		instructions.reserve(text.size());

		for (int32 i = 0; i < text.size(); i++)
		{
			Instruction inst = { text[i].substr(0, 3), atoi(text[i].substr(4).c_str()) };
			instructions.push_back(inst);
		}
	}

	int32 globalValue = 0;
	for (int32 i = 0; i < instructions.size(); i++)
	{
		Instruction* in = &instructions[i];
		if (in->executed)
			break;
		else if (in->instruction == "acc")
		{
			globalValue += in->argument;
		}
		else if (in->instruction == "jmp")
		{
			i += in->argument - 1;
		}
		in->executed = true;
	}

	result = globalValue;

	printf("Answer: %i\n\n", result);
	return result;
}


int32 Day8Part2()
{
	printf("Day 8 part 8:\n");
	int32 result = 0;

	std::vector<Instruction> instructions;
	{
		std::vector<std::string> text = FileToStringArray("Day8_Data.txt");
		instructions.reserve(text.size());

		for (int32 i = 0; i < text.size(); i++)
		{
			Instruction inst = { text[i].substr(0, 3), atoi(text[i].substr(4).c_str()) };
			instructions.push_back(inst);
		}
	}

	int32 globalValue = 0;
	for (int32 j = 0; j < instructions.size(); j++)
	{
		if (instructions[j].instruction != "acc")
		{
			if (instructions[j].instruction == "nop")
				instructions[j].instruction = "jmp";
			else 
				instructions[j].instruction = "nop";

			std::vector<bool> executed;
			executed.resize(instructions.size());
			bool infiniteLoop = false;
			globalValue = 0;

			for (int32 i = 0; i < instructions.size() && !infiniteLoop; i++)
			{

				Instruction* in = &instructions[i];
				if (executed[i])
					infiniteLoop = true;
				else
					executed[i] = true;
				if (in->instruction == "acc")
				{
					globalValue += in->argument;
				}
				else if (in->instruction == "jmp")
				{
					i += in->argument - 1;
				}

			}
			if (!infiniteLoop)
				break;

			if (instructions[j].instruction == "nop")
				instructions[j].instruction = "jmp";
			else
				instructions[j].instruction = "nop";
		}
	}

	result = globalValue;
	printf("Answer: %i\n\n", result);
	return result;
}
