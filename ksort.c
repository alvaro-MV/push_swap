#include "stack_ops.h"
#include "dictionary.h"
#include "quicksort.h"

dictionary    *get_dict_from_stack(stack_head *a)
{
    unsigned int    i = 0;
    int             *array;
    dic_entry       *entry;
    dictionary      *dic = dict_init(2 * (a->len));

    array = get_array(a);
    quicksort(array, 0, a->len - 1);
    dic = dict_init(2 * (a->len));
    if (dic == NULL)
        return (NULL);
    while (i < a->len)
    {
        entry = (dic_entry*) malloc(sizeof(dic_entry));
        if (entry == NULL)
            return (dict_delete(dic), NULL);
        entry->key = ft_itoa(array[i]);
        entry->value = ft_itoa(i);
        dict_insert(&dic, entry);
        i++;
    }
    return (dic);
}

void    put_indexes_stack(stack_head *a, dictionary *dic)
{
    stack_node  *tmp;

    tmp = a->head;
    while (tmp)
    {
        tmp->index = dict_get(dic, ft_itoa(tmp->content));
        tmp = tmp->next;
    }
}

k_sort1(stack_head *a, stack_head *b)
{
    
}