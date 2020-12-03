#pragma once

#include <cassert>
#include <vector>
#include <string>

std::vector<int> TextToIntArray(const char* text, const char lineEnd);
std::vector<int> TextToIntArray(const char* text);
std::vector<int> FileToIntArray(const char* fileName, const char lineEnd);
std::vector<std::string> FileToStringArray(const char* fileName);
