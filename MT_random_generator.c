#include "mersenne_twister.h"
#include <stdio.h>
#include <unistd.h>
#include "lib/include/libft.h"

static MTrand  *get_rand_generator(unsigned int seed)
{
    MTrand          *rand;
    unsigned int     value;

    rand = (MTrand*) malloc(sizeof(MTrand));
    if (!rand)
        return (NULL);
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

void    next_state_value(MTrand *rand, int k1, int k, int *a, int distance)
{
    unsigned int y;
    unsigned int rand_m;

    y = (rand->vector[k] & UPPER_MASK)
        | (rand->vector[k1] & LOWER_MASK);
    rand_m = rand->vector[(k + distance)];
    rand->vector[k] = rand_m ^ (y >> 1) ^ a[y & 0x1];
}

float MT_recursion(MTrand *rand)
{
    float y;
    unsigned int k;
    unsigned int k1;
    unsigned int a[2];

    a[0] = 0x0;
    a[1] = A_M;
    k = 0;
    while (k < N - M)
    {
        k1 = (k + 1) % N;
        next_state_value(rand, k1, k, a, M);
        k = k1;
    }
    while (k < N-1)
    {
        k1 = (k + 1) % N;
        next_state_value(rand, k1, k, a, M - N);
        k = k1;
    }
    next_state_value(rand, k1, k, a, M - N);
    y = (float) tempering(rand->vector[N-1]);
    y /= 4294967295;
    return (y);
}

float get_random_value(int seed)
{
    static MTrand  *rand;
    float           y;
    unsigned int    s;

    if (seed <= 0)
        s = INITIAL_SEED;
    if (!rand)
    {
        rand = get_rand_generator(INITIAL_SEED);
        if (!rand)
            return (-1);
    }
    y = MT_recursion(rand);
    return (y);
}

int main(void)
{
    float   next_number;
    MTrand  *rand;

    next_number = get_random_value(0);
    if (next_number == -1)
        return (0);
    printf("next_number: %f\n", next_number);
    next_number = get_random_value(0);
    printf("next_number: %f\n", next_number);
    next_number = get_random_value(0);
    printf("next_number: %f\n", next_number);
}