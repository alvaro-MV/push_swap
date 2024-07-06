#include "mersenne_twister.h"
#include <stdio.h>
#include <unistd.h>
#include "lib/include/libft.h"

static MTrand  *get_rand_generator(int seed)
{
    MTrand  *rand;
    int     value;

    rand = (MTrand*) malloc(sizeof(MTrand));
    rand->index = 1;
    rand->vector[0] = seed & 0xffffffff;
    while (rand->index < N)
    {
        value = rand->vector[rand->index];
        value = (6069 * rand->vector[rand->index-1]) & 0xffffffff;
        rand->vector[rand->index] = value;
        rand->index++;
    }
    return (rand);
}

static int tempering(int y)
{
    y ^= (y >> 11);
    y ^= ((y << 7) & 0x9d2c5680);
    y ^= ((y << 15) & 0xefc60000);
    y ^= (y >> 18);
    return (y);
}

void    next_state_value(MTrand *rand, int k1, int *a, int distance)
{
    int y;
    int rand_m;

    rand->vector[k1 - 1] & UPPER_MASK;
    y = (rand->vector[k1 - 1] & UPPER_MASK)
        | (rand->vector[k1] & LOWER_MASK);
    rand_m = rand->vector[(k1 - 1 + distance) % N];
    rand->vector[k1 - 1] = rand_m ^ (y >> 1) ^ a[y & 0x1];
}

float MT_recursion(MTrand *rand)
{
    int y;
    int k;
    int k1;
    int a[2];

    a[0] = 0x0;
    a[1] = A_M;
    k = 0;
    while (k < N - M)
    {
        k1 = (k + 1) % N;
        next_state_value(rand, k1, a, M);
        k = k1;
    }
    while (k < N - 1)
    {
        k1 = (k + 1) % N;
        next_state_value(rand, k1, a, M - N);
        k = k1;
    }
    y = (float) tempering(rand->vector[k]);
    //y /= 4294967295;
    return (y);
}

int get_random_value(void)
{
    static MTrand   *rand;
    int             y;

    if (rand)
        rand = get_rand_generator(INITIAL_SEED);
    y = MT_recursion(rand);
    return (y);
}

int main(void)
{
    int             next_number;

    next_number = get_random_value();
    printf("next_number: %d\n", next_number);
    next_number = get_random_value();
    printf("next_number: %d\n", next_number);
    next_number = get_random_value();
    printf("next_number: %d\n", next_number);
    next_number = get_random_value();
    printf("next_number: %d\n", next_number);
}