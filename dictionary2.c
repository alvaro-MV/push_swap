#include "dictionary.h"
#include <string.h>

void    *dict_get(dictionary *dic, char *key)
{
    unsigned int    index;
    unsigned int    counter;
    
    if (key == NULL)
        return (NULL);
    index = dict_hash(key) % dic->capacity;
    counter = 0;
    while (counter < dic->capacity - 1)
    {
        if (dic->entries[index] 
            && !strcmp(dic->entries[index]->key, key))
            return (dic->entries[index]->value);
        index++;
        if (index == dic->capacity - 1)
            index = 0;
        counter++;
    }
    return (NULL);
}

unsigned int    dict_hash(char *key)
{
    unsigned int    hash;
    int             i;
    int             length;

    hash = 2166136261u;
    i = 0;
    length = ft_strlen(key);
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
    while (i < dic->capacity)
    {
        if (dic->entries[i] != NULL)
        {
            free(dic->entries[i]->key);
            free(dic->entries[i]->value);
        }
        free(dic->entries[i]);
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
    dic_entry   *entry;
    dictionary  *dic = dict_init(15);
    while (i < 4)
    {
        entry = (dic_entry*) malloc(sizeof(dic_entry));
        entry->key = ft_itoa(array[i]);
        entry->value = ft_itoa(i);
        printf("key: %s,  value: %s\n", entry->key, entry->value);
        dict_insert(dic, entry);
        i++;
    }
    printf("value: %s", (char *) dict_get(dic, "12"));
    dict_delete(dic);
}