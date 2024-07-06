#ifndef MERSENNE_TWISTER_
# define MERSENNE_TWISTER_

# define INITIAL_SEED 5489
# define LOWER_MASK 0x7fffffff
# define UPPER_MASK 0x80000000
# define N 624
# define M 3
# define A_M 0x9908b0df

typedef struct  MTRandGen
{
    int vector[N];
    int index;
}       MTrand;

#include <stdlib.h>

#endif