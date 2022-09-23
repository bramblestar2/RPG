#include "../Headers/Misc.h"
#include <iostream>

float Misc::lerp(float a, float b, float t)
{
    return a + t * (b - a);
}
