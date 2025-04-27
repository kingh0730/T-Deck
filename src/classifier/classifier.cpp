#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Xor
{
    float or_w1;
    float or_w2;
    float or_b;
    float nand_w1;
    float nand_w2;
    float nand_b;
    float and_w1;
    float and_w2;
    float and_b;
} Xor;

float train[][3] = {
    {0, 0, 0},
    {0, 1, 1},
    {1, 0, 1},
    {1, 1, 0},
};

#define TRAIN_SIZE (sizeof(train) / sizeof(train[0]))

float rand_float(void)
{
    return (float)rand() / (float)(RAND_MAX);
}

float sigmoid(float x)
{
    return 1.0f / (1.0f + expf(-x));
}

float forward(float w1, float w2, float b, float x1, float x2)
{
    return sigmoid(x1 * w1 + x2 * w2 + b);
}

float cost(float w1, float w2, float b)
{
    float cost = 0.0f;
    for (size_t i = 0; i < TRAIN_SIZE; i++)
    {
        float x1 = train[i][0];
        float x2 = train[i][1];
        float y = train[i][2];
        float z = forward(w1, w2, b, x1, x2);
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

    float w1 = rand_float() * 1.0f;
    float w2 = rand_float() * 1.0f;
    float b = rand_float() * 1.0f;
    printf("w1: %f, w2: %f, b: %f\n", w1, w2, b);

    float cost_value = cost(w1, w2, b);
    printf("cost: %f\n", cost_value);

    float epsilon = 0.01f;
    float alpha = 0.01f;

    for (size_t i = 0; i < 1 * 1000 * 1000; i++)
    {
        float c = cost(w1, w2, b);
        // * Plot
        // printf("%f\n", c);

        float dw1 = (cost(w1 + epsilon, w2, b) - c) / epsilon;
        float dw2 = (cost(w1, w2 + epsilon, b) - c) / epsilon;
        float db = (cost(w1, w2, b + epsilon) - c) / epsilon;
        // printf("dw1: %f, dw2: %f, db: %f\n", dw1, dw2, db);

        w1 -= alpha * dw1;
        w2 -= alpha * dw2;
        b -= alpha * db;
    }

    printf("w1: %f, w2: %f, b: %f\n", w1, w2, b);
    printf("cost: %f\n", cost(w1, w2, b));

    for (size_t i = 0; i < TRAIN_SIZE; i++)
    {
        float x1 = train[i][0];
        float x2 = train[i][1];
        float y = train[i][2];
        float z = forward(w1, w2, b, x1, x2);
        printf("x1: %f, x2: %f, y: %f, z: %f\n", x1, x2, y, z);
    }
}
