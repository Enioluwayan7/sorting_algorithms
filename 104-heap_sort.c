#include "sort.h"
void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);
/**
* swap_ints - Swap two integers in an array.
* @a: The first integer to swap.
* @b: The second integer to swap.
*/
void swap_ints(int *a, int *b)
{
	int tm_p;
	tm_p = *a;
	*a = *b;
	*b = tm_p;
}
/**
* max_heapify - Turn a binary tree into a complete binary heap.
* @array: An array of integers representing a binary tree.
* @size: The size of the array/tree.
* @base: The index of the base row of the tree.
* @root: The root node of the binary tree.
*/
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, rigt, larg;
	left = 2 * root + 1;
	rigt = 2 * root + 2;
	larg = root;
	if (left < base && array[left] > array[larg])
		larg = left;
	if (rigt < base && array[rigt] > array[larg])
		larg = rigt;
	if (larg != root)
		{swap_ints(array + root, array + larg);
	print_array(array, size);
	max_heapify(array, size, base, larg);
		}
}
/**
* heap_sort - Sort an array of integers in ascending
*
order using the heap sort algorithm.
* @array: An array of integers.
* @size: The size of the array.
*
* Description: Implements the sift-down heap sort
* algorithm. Prints the array after each swap.
*/
void heap_sort(int *array, size_t size)
{
	int k;
	if (array == NULL || size < 2)
		return;
	for (k = (size / 2) - 1; k >= 0; k--)
		max_heapify(array, size, size, k);
	for (k = size - 1; k > 0; k--)
		{
			swap_ints(array, array + k);
			print_array(array, size);
			max_heapify(array, size, k, 0);
		}
}
