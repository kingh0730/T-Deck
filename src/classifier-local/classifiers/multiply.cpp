#include <stdio.h>
#include <stdlib.h>

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

float cost(float w, float b)
{
    float cost = 0.0f;
    for (size_t i = 0; i < TRAIN_SIZE; i++)
    {
        float x = train[i][0];
        float y = train[i][1];
        float z = x * w + b;
        float d = z - y;
        cost += d * d;
        // printf("x: %f, y: %f, z: %f, d: %f\n", x, y, z, d);
    }
    cost /= TRAIN_SIZE;
    return cost;
}

void classify(void)
{
    srand(730);

    printf("TRAIN_SIZE: %zu\n", TRAIN_SIZE);

    float w = rand_float() * 10.0f;
    float b = rand_float() * 5.0f;
    printf("w: %f, b: %f\n", w, b);

    float cost_value = cost(w, b);
    printf("cost: %f\n", cost_value);

    float epsilon = 0.01f;
    float alpha = 0.01f;

    for (size_t i = 0; i < 500; i++)
    {
        float dw = (cost(w + epsilon, b) - cost(w, b)) / epsilon;
        float db = (cost(w, b + epsilon) - cost(w, b)) / epsilon;
        // printf("dw: %f, db: %f\n", dw, db);

        w -= alpha * dw;
        b -= alpha * db;
    }

    printf("w: %f, b: %f\n", w, b);
}
