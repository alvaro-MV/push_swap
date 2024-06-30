#include "stack_ops.h"

int	get_array(stack *a)
{
	size_t	list_len;
	size_t	i;
	int		*array;

	list_len = stack_size(a);
	i = 0;
	array = (int *) malloc(sizeof(int) * list_len);
	while (i < list_len)
	{
		array[i] = *(int *) a->content;
		a->next;
		i++;
	}
	return (array);
}

void	ft_swap(int *array, int pos1, int pos2)
{
    array[pos1], array[pos2] = array[pos2], array[pos1];
    return (array);
}

void	partitioning(int *array, size_t len)
{
	int	cursor_i;
	int	cursor_d;
	int	pivot;
	int	flag;

	cursor_i = 0;
	cursor_d = len - 2;
	pivot = len -1;
	flag = 1;
	while (1)
	{
		if (flag)
		{
			if (array[cursor_i] >= array[pivot])
			{
				flag = 0;
				continue ;
			}
			cursor_i++;
		}
		else
		{
			if (array[cursor_d] <= array[pivot])
				break ;
			cursor_d--;
		}
	}
	if (cursor_i >= cursor_d)
	{
		swapPositions(array, cursor_i, pivot);
        return array, cursor_i;
	}
   else
   {
        ft_swap(array, cursor_i, cursor_d);
        return partioning(array, cursor_i, cursor_d);
   }
}

//def quicksort(array):
    //prim_part, pivotal = partioning(array)
    //pivot_movil = pivotal
    //print("dcha: ----------------------------")#testeo
    //while True:
        //if pivot_movil == 0:
            //break
        //dcha = prim_part[:pivot_movil]
        //dcha = partioning(dcha)
        //print("valor dcha: ", dcha)#testeo
        //print("prim part[:pivot_movil]: ", prim_part[:pivot_movil])#testeo
        //for i in range(len(dcha[0])):
            //print("i: ", i)#testeo
            //print(prim_part)#testeo
            //print("dcha: ", dcha)#testeo
            //print("dcha[0][i]: ", dcha[0][i])#testeo
            //prim_part[i] = dcha[0][i]
            //print("prim_part_derecha: ",prim_part)#testeo
            //print("pivotal: ", pivotal)
        //pivot_movil -= 1
    
    //pivot_movil = pivotal+1
    //print("izq: ----------------------------")#testeo
    //while True:
        //print("pivot_movil", pivot_movil)
        //if pivot_movil == len(array)-1:
            //break
        //izq = prim_part[pivot_movil:]
        //izq = partioning(izq)
        //print("dsgrdhjyfyj",izq)#testeo
        //for i in range(len(izq[0])):
            //print("i: ", i)#testeo
            //print(prim_part)#testeo
            //print("izq: ", izq)#testeo
            //print("izq[0][i]: ", izq[0][i])#testeo
            //prim_part[i+pivot_movil] = izq[0][i]
            
        //pivot_movil += 1
        
    //return prim_part
