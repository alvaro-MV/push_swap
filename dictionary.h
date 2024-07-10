#ifndef DICTIONARY_H
# define DICTIONARY_H

#include <stdlib.h>

# define FNV_OFFSET 2166136261
# define FNV_PRIME 16777619
# define INITIAL_CAPACITY 16

typedef struct dic_e
{
    char    *key;
    void    *value;   
}           dic_entry;

typedef struct dict
{
    dic_entry   *entries;
    int         n_elements;
    int         capacity;
}               dictionary;


#endif