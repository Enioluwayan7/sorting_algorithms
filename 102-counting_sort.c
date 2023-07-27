#include "sort.h"
/**
* get_max - Get the maximum value in an array of integers.
* @array: An array of integers.
* @size: The size of the array.
*
* Return: The maximum integer in the array.
*/
int get_max(int *array, int size)
{
	int maxi, j;
	for (maxi = array[0], j = 1; j < size; j++)
		{
			if (array[j] > maxi)
				maxi = array[j];
		}
		return (maxi);
}
/**
* counting_sort - Sort an array of integers in ascending order
* using the counting sort algorithm.
* @array: An array of integers.
* @size: The size of the array.
*
* Description: Prints the counting array after setting it up.
*/
void counting_sort(int *array, size_t size)
{
	int *cont, *sort, max, i;
	if (array == NULL || size < 2)
		return;
	sort = malloc(sizeof(int) * size);if (sort == NULL)
	return;
	max = get_max(array, size);
	cont = malloc(sizeof(int) * (max + 1));
	if (cont == NULL)
		{
			free(sort);
			return;
		}
		for (i = 0; i < (max + 1); i++)
			cont[i] = 0;
		for (i = 0; i < (int)size; i++)
			cont[array[i]] += 1;
		for (i = 0; i < (max + 1); i++)
			cont[i] += cont[i - 1];
		print_array(cont, max + 1);
		for (i = 0; i < (int)size; i++)
			{
				sort[cont[array[i]] - 1] = array[i];
				cont[array[i]] -= 1;
			}
			for (i = 0; i < (int)size; i++)
				array[i] = sort[i];
			free(sort);
			free(cont);
}
