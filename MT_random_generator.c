#include "mersenne_twister.h"
#include <stdio.h>

static MTrand  *get_rand(int seed)
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

int MT_recursion(MTrand *rand)
{
    int         y;
    static int  k;
    int         k1;
    int         rand_m;
    int         a[2];

    a[0] = 0x0;
    a[1] = A_M;
    k1 = (k + 1) % N;
    y = (rand->vector[k] & UPPER_MASK)
        | (rand->vector[k1] & LOWER_MASK);
    rand_m = rand->vector[(k + M) % N];
    rand->vector[k] = rand_m ^ (y >> 1) ^ a[y & 0x1];
    y = tempering(rand->vector[k]);
    k = k1;
    return (y);
}

int main(void)
{
    MTrand          *rand;
    int             next_number;

    rand = get_rand(547);
    next_number = MT_recursion(rand);
    printf("next_number: %d\n", next_number);
    next_number = MT_recursion(rand);
    printf("next_number: %d\n", next_number);
    next_number = MT_recursion(rand);
    printf("next_number: %d\n", next_number);
    next_number = MT_recursion(rand);
    printf("next_number: %d\n", next_number);
    next_number = MT_recursion(rand);
    printf("next_number: %d\n", next_number);
    next_number = MT_recursion(rand);
    printf("next_number: %d\n", next_number);
    next_number = MT_recursion(rand);
    printf("next_number: %d\n", next_number);
}