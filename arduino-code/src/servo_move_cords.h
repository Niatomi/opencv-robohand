#include <math.h>

float a_base(float x, float y)
{
    return atan(y / x);
}

float x_1(float x, float y, float l1)
{
    return x - l1 * cos(a_base(x, y));
}

float y_1(float x, float y, float l1)
{
    return y - l1 * sin(a_base(x, y));
}

float a_2(float x, float y, float z, float l1, float l2, float l3)
{
    float r2 = pow(x_1(x, y, l1), 2) + pow(y_1(x, y, l1), 2) + pow(z, 2);
    float betta2 = acos((pow(l3, 2) + pow(l2, 2) - r2) / (2 * l3 * l2));
    return M_PI - betta2;
}

float a_3(float x, float y, float z, float l1, float l2, float l3)
{
    float r = sqrt(pow(x_1(x, y, l1), 2) + pow(y_1(x, y, l1), 2) + pow(z, 2));
    float gamma = asin(z / r);
    float betta3 = acos((pow(l3, 2) + pow(r, 2) - pow(l2, 2)) / (2 * l3 * r));
    return (M_PI / 2) - betta3 - gamma;
}

float a_1(float x, float y, float z, float l1, float l2, float l3)
{
    return M_PI / 2 - a_2(x, y, z, l1, l2, l3) - a_3(x, y, z, l1, l2, l3);
}