#include "dictionary.h"
#include "lib/include/libft.h"

dictionary  *dict_init(int *capacity)
{
    dictionary  *dic;
    dic_entry   *entries;
    int         dic_capacity;

    dic = (dictionary*) malloc(sizeof(dictionary));
    if (!dic)
        return (NULL);
    if (capacity == NULL)
        dic_capacity = INITIAL_CAPACITY;
    else
        dic_capacity = *capacity;
    dic->capacity = dic_capacity;
    dic->n_elements = 0;
    entries = ft_calloc(dic_capacity, sizeof(dic_entry));
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
        if (!dic_expand(&dic))
        {
            dic_delete(dic);
            return ;
        }
    }
    hash_entry = dic_hash(entry.key);
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
void    *dic_get(dictionary *dic, char *key)
{
    unsigned int    index;
    int             counter;
    
    if (key == NULL)
        return (NULL);
    index = dic_hash(key) % dic->capacity;
    while (counter < dic->capacity - 1)
    {
        if (dic->entries[index].key == key)
            return (dic->entries[index].value);
        index++;
        if (index == dic->capacity - 1)
            index = 0;
        counter++;
    }
    return (NULL);
}

int  dic_expand(dictionary **dic_pointer)
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
            new_index = dic_hash(old_dic->entries[i].key) % new_capacity;
            new_dic->entries[new_index] = old_dic->entries[i];
            new_dic->n_elements++;
        }
        i++;
    }
    dic_delete(*dic_pointer);
    dic_pointer = new_dic;
    return (0);
}
void    dic_delete(dictionary *dic)
{
    int i;

    i = 0;
    free(dic->entries);
    free(dic);
}
//init, hash, get, insert, expand, delete.