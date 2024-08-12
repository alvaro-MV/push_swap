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

//#include "sort_algorithms.h"
//#include "stack_ops.h"
//#include "lib/include/libft.h"
//#include "quicksort.h"
//#include "stack_io.h"

//int main(int argc, char **argv)
//{
    //int    i = 0;
    //dic_entry       *entry;
    //dictionary      *dic = dict_init(15);
	//stack_head	    *a;
	//stack_head	    *b;
    //int             *array;

	//a = ft_calloc(1, sizeof(stack_head));
	//if (a == NULL)
		//return (-1);
	//b = ft_calloc(1, sizeof(stack_head));
	//if (b == NULL)
		//return (-1);
	//argv++;
    //argv = parse_args(argc - 1, argv);
    //a = read_list_argum(argc-1, argv, a);
    //if (a  == NULL)
        //return (0);
    //array = get_array(a);
    //i = 0;
    //while (i < argc - 1)
    //{
        //entry = (dic_entry*) malloc(sizeof(dic_entry));
        //entry->key = ft_itoa(array[i]);
        //entry->value = ft_itoa(i);
        //dict_insert(&dic, entry);
        //i++;
    //}
    //ft_printf("i:  %d", i);
    //ft_printf("dic:get val: %s", dict_get(dic, "27"));
    //dict_delete(dic);
//}