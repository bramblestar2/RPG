#include "../Headers/Extra.h"

float Extra::lerp(float a, float b, float t)
{
    return a + t * (b - a);
}
