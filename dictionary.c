#include "dictionary.h"

dictionary  *dict_init(int capacity)
{
    dictionary  *dic;
    dic_entry   *entries;
    int         dic_capacity;

    dic = (dictionary*) malloc(sizeof(dictionary));
    if (!dic)
        return (NULL);
    if (capacity <= 0)
        dic_capacity = INITIAL_CAPACITY;
    else
        dic_capacity = capacity;
    dic->capacity = dic_capacity;
    dic->n_elements = 0;
    entries = (dic_entry *) ft_calloc(dic_capacity, sizeof(dic_entry));
    if (!entries)
    {
        free(dic);
        return (NULL);
    }
    dic->entries = entries;
    return (dic);
}

void    dict_insert(dictionary *dic, dic_entry entry)
{
    unsigned int    hash_entry;
    unsigned int    index;

    if (entry.key == NULL)
        return ;
    if (dic->n_elements > (dic->capacity / 2))
    {
        if (!dict_expand(&dic))
        {
            dict_delete(dic);
            return ;
        }
    }
    hash_entry = dict_hash(entry.key, 10);
    index = hash_entry % dic->capacity;
    while (dic->entries[index].key != NULL)
    {
        index++;
        if (index == dic->capacity - 1)
            index = 0;
    }
    dic->entries[index] = entry;
    dic->n_elements++;
}

int  dict_expand(dictionary **dic_pointer)
{
    int         new_capacity;
    int         new_index;
    int         i;
    dictionary  *old_dic;
    dictionary  *new_dic;

    old_dic = *dic_pointer;
    new_capacity = old_dic->capacity * 2;
    new_dic = dict_init(new_capacity);
    if (new_dic == NULL)
        return (-1);
    i = 0;
    while (old_dic->n_elements)
    {
        if (old_dic->entries[i].key != NULL)
        {
            new_index = dict_hash(old_dic->entries[i].key, 10) % new_capacity;
            new_dic->entries[new_index] = old_dic->entries[i];
            new_dic->n_elements++;
        }
        i++;
    }
    dict_delete(*dic_pointer);
    *dic_pointer = new_dic;
    return (0);
}
