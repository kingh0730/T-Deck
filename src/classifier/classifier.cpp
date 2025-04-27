#include <stdio.h>

float train[][2] = {
    {0, 0},
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 8},
};

#define TRAIN_SIZE (sizeof(train) / sizeof(train[0]))

float rand_float(void)
{
    return (float)rand() / (float)(RAND_MAX);
}

void classify(void)
{
    srand(730);

    float w = rand_float() * 10.0f;
    printf("w: %f\n", w);

    float error = 0.0f;
    for (size_t i = 0; i < TRAIN_SIZE; i++)
    {
        float x = train[i][0];
        float y = train[i][1];
        float z = x * w;
        float d = z - y;
        error += d * d;
        printf("x: %f, y: %f, z: %f, d: %f\n", x, y, z, d);
    }

    error /= TRAIN_SIZE;
    printf("error: %f\n", error);
}
