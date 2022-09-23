#pragma once
#define fileLine() std::cout << __FILE__ << " | Line " << __LINE__ << " | Function " << __func__ << ": "

namespace Misc
{
	float lerp(float a, float b, float t);
}