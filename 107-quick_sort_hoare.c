#include "sort.h"
void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);
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
* hoare_partition - Order a subset of an array of integers
*
according to the hoare partition scheme.* @array: The array of integers.
* @size: The size of the array.
* @left: The starting index of the subset to order.
* @right: The ending index of the subset to order.
*
* Return: The final partition index.
*
* Description: Uses the last element of the partition as the driver.
* Prints the array after each swap of two elements.
*/
int hoare_partition(int *array, size_t size, int left, int right)
{
	int drivers, ups, downs;
	drivers = array[right];
	for (ups = left - 1, downs = right + 1; ups < downs;)
		{
			do {
				ups++;
			} while (array[ups] < drivers);
			do {
				downs--;
			} while (array[downs] > drivers);
			if (ups < downs)
				{
					swap_ints(array + ups, array + downs);
					print_array(array, size);
				}
		}
return (ups);
}
/**
* hoare_sort - Implement the quicksort algorithm through recursion.
* @array: An array of integers to sort.
* @size: The size of the array.
* @left: The starting index of the array partition to order.
* @right: The ending index of the array partition to order.*
* Description: Uses the Hoare partition scheme.
*/
void hoare_sort(int *array, size_t size, int left, int right)
{
	int bel;
	if (right - left > 0)
		{
			bel = hoare_partition(array, size, left, right);
			hoare_sort(array, size, left, bel - 1);
			hoare_sort(array, size, bel, right);
		}
}
/**
* quick_sort_hoare - Sort an array of integers in ascending
* order using the quicksort algorithm.
* @array: An array of integers.
* @size: The size of the array.
*
* Description: Uses the Hoare partition scheme. Prints
* the array after each swap of two elements.
*/
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	hoare_sort(array, size, 0, size - 1);
}
