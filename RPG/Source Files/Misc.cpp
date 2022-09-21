#include "../Headers/Misc.h"

float Misc::lerp(float a, float b, float t)
{
    return a + t * (b - a);
}
