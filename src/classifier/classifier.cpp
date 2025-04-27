#include <stdio.h>

float train[][2] = {
    {0, 0},
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 8},
};

float rand_float(void)
{
    return (float)rand() / (float)(RAND_MAX);
}

void classify(void)
{
    srand(730);

    float w = rand_float() * 10;
    printf("w: %f\n", w);
}
