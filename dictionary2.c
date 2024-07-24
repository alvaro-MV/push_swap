#include "dictionary.h"
#include <string.h>

char    *dict_get(dictionary *dic, char *key)
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

//int main(void)
//{
    //int             array[] = {454, 432, 0, 264, 23, 344, 251, 313, 293, 441, 199, 190, 197, 50, 168, 413, 91, 150, 409, 405, 32, 296, 148, 111, 302, 57, 325, 151, 98, 273, 428, 104, 490, 165, 308, 427, 130, 326, 387, 236, 312, 125, 155, 418, 357, 246, 292, 336, 323, 81, 340, 451, 465, 393, 252, 164, 173, 341, 479, 76, 176, 239, 215, 187, 274, 331, 75, 217, 304, 159, 124, 102, 47, 300, 35, 99, 243, 248, 367, 184, 444, 214, 60, 225, 334, 468, 24, 457, 1, 360, 136, 249, 328, 245, 276, 467, 277, 358, 484, 44, 8, 265, 395, 192, 279, 384, 494, 338, 89, 193, 332, 202, 19, 127, 114, 306} ;
    //unsigned int    i = 0;
    //dic_entry       *entry;
    //dictionary      *dic = dict_init(15);
    //while (i < 500)
    //{
        //entry = (dic_entry*) malloc(sizeof(dic_entry));
        //entry->key = ft_itoa(array[i]);
        //entry->value = ft_itoa(i);
        //dict_insert(&dic, entry);
        //i++;
    //}
    //printf("value: %s", (char *) dict_get(dic, "384"));
    //dict_delete(dic);
//}