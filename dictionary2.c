#include "dictionary.h"

void    *dict_get(dictionary *dic, char *key)
{
    unsigned int    index;
    char            *prueba; //testeo
    unsigned int    counter;
    
    if (key == NULL)
        return (NULL);
    index = dict_hash(key, 10) % dic->capacity;
    counter = 0;
    while (counter < dic->capacity - 1)
    {
        prueba = dic->entries[index].key; //testeo
        if (dic->entries[index].key == key)
            return (dic->entries[index].value);
        index++;
        if (index == dic->capacity - 1)
            index = 0;
        counter++;
    }
    return (NULL);
}

unsigned int    dict_hash(char *key, int length)
{
    unsigned int    hash;
    int             i;

    hash = 2166136261u;
    i = 0;
    while (i < length)
    {
        hash ^= (uint8_t) key[i];
        hash *= 16777619;
        i++;
    }
    return (hash);
}

void    dict_delete(dictionary *dic)
{
    unsigned int    i;

    i = 0;
    while (i < dic->n_elements)
    {
        free(dic->entries[i].key);
        free(dic->entries[i].value);
        i++;
    }
    free(dic->entries);
    free(dic);
}

#include <stdio.h>

int main(void)
{
    int         array[] = {12, 44, 456, 1230};
    int         i = 0;
    dic_entry   entry;
    dictionary  *dic = dict_init(15);
    while (i < 4)
    {
        entry.key = ft_itoa(array[i]);
        entry.value = ft_itoa(i);
        dict_insert(dic, entry);
        i++;
    }
    printf("value: %s", (char *) dict_get(dic, "12"));
    dict_delete(dic);
}