#pragma once

#include <cassert>
#include <vector>
#include <string>
#include <cstdint>

using int8 = int8_t;
using int16 = int16_t;
using int32 = int32_t;
using int64 = int64_t;

using uint8 = uint8_t;
using uint16 = uint16_t;
using uint32 = uint32_t;
using uint64 = uint64_t;

const float pi = 3.14159f;
const float tau = 2 * pi;
const float inf = INFINITY;

struct Vector {
	float x = 0;
	float y = 0;
};

struct Vectori {
	int32 x = 0;
	int32 y = 0;
};

inline Vector operator-(const Vector& lhs, const Vector& rhs)
{
    return { lhs.x - rhs.x, lhs.y - rhs.y };
}
inline Vectori operator-(const Vectori& lhs, const Vectori& rhs)
{
    return { lhs.x - rhs.x, lhs.y - rhs.y };
}

inline Vector operator-(const Vector& lhs, const float rhs)
{
    return { lhs.x - rhs, lhs.y - rhs };
}
inline Vectori operator-(const Vectori& lhs, const int32 rhs)
{
    return { lhs.x - rhs, lhs.y - rhs };
}

inline Vector operator+(const Vector& lhs, const Vector& rhs)
{
    return { lhs.x + rhs.x, lhs.y + rhs.y };
}
inline Vectori operator+(const Vectori& lhs, const Vectori& rhs)
{
    return { lhs.x + rhs.x, lhs.y + rhs.y };
}


inline Vector operator*(const Vector& a, const float b)
{
    return { a.x * b,  a.y * b };
}
inline Vectori operator*(const Vectori& a, const int32 b)
{
    return { int(a.x * b),  int(a.y * b) };
}

inline Vector operator/(const Vector& a, const float b)
{
    return { a.x / b,  a.y / b };
}
inline Vectori operator/(const Vectori& a, const int32 b)
{
    return { a.x / b,  a.y / b };
}


inline const Vector& operator+=(Vector& lhs, const Vector& rhs)
{
    return { lhs.x += rhs.x, lhs.y += rhs.y };
}
inline const Vectori& operator+=(Vectori& lhs, const Vectori& rhs)
{
    return { lhs.x += rhs.x, lhs.y += rhs.y };
}


inline bool operator==(const Vector& lhs, const Vector& rhs)
{
    return ((lhs.x == rhs.x) && (lhs.y == rhs.y));
}
inline bool operator==(const Vectori& lhs, const Vectori& rhs)
{
    return ((lhs.x == rhs.x) && (lhs.y == rhs.y));
}


inline bool operator!=(const Vector& lhs, const Vector& rhs)
{
    return !(lhs == rhs);
}
inline bool operator!=(const Vectori& lhs, const Vectori& rhs)
{
    return !(lhs == rhs);
}

std::vector<int> TextToIntArray(const char* text, const char lineEnd);
std::vector<int> TextToIntArray(const char* text);
std::vector<int> FileToIntArray(const char* fileName, const char lineEnd);
std::vector<std::string> FileToStringArray(const char* fileName);
