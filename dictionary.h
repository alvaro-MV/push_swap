#ifndef DICTIONARY_H
# define DICTIONARY_H

#include <stdlib.h>
#include "lib/include/libft.h"
#include <stdint.h>

# define FNV_OFFSET 2166136261
# define FNV_PRIME 16777619
# define INITIAL_CAPACITY 16

typedef struct dic_e
{
    char    *key;
    char    *value;   
}           dic_entry;

typedef struct dict
{
    dic_entry       **entries;
    unsigned int    n_elements;
    unsigned int    capacity;
}                   dictionary;

dictionary      *dict_init(int capacity);
void            dict_insert(dictionary **dic, dic_entry *entry);
//int             dict_expand(dictionary **dic_pointer);
void            *dict_get(dictionary *dic, char *key);
unsigned int    dict_hash(char *key);
void            dict_delete(dictionary *dic);

#endif