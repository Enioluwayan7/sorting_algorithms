#include "sort.h"
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid, size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);
/**
* merge_subarr - Sort a subarray of integers.
* @subarr: A subarray of an array of integers to sort.
* @buff: A buffer to store the sorted subarray.
* @front: The front index of the array.
* @mid: The middle index of the array.
* @back: The back index of the array.
*/
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid, size_t back)
{
	size_t i, m, k = 0;
	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);
	printf("[right]: ");
	print_array(subarr + mid, back - mid);
	for (i = front, m = mid; i < mid && m < back; k++)
		buff[k] = (subarr[i] < subarr[m]) ? subarr[i++] : subarr[m++];
	for (; i < mid; i++)
		buff[k++] = subarr[i];
	for (; m < back; m++)
		buff[k++] = subarr[m];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buff[k++];
	printf("[Done]: ");
	print_array(subarr + front, back - front);
}
/**
* merge_sort_recursive - Implement the merge sort algorithm through recursion.
* @subarr: A subarray of an array of integers to sort.
* @buff: A buffer to store the sorted result.
* @front: The front index of the subarray.
* @back: The back index of the subarray.
*/
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;
	if (back - front > 1)
		{
			mid = front + (back - front) / 2;
			merge_sort_recursive(subarr, buff, front, mid);
			merge_sort_recursive(subarr, buff, mid, back);
			merge_subarr(subarr, buff, front, mid, back);
		}
}
/**
* merge_sort - Sort an array of integers in ascending
* order using the merge sort algorithm.
* @array: An array of integers.
* @size: The size of the array.
*
* Description: Implements the top-down merge sort algorithm.
*/
void merge_sort(int *array, size_t size)
{
	int *buffs;
	if (array == NULL || size < 2)
		return;
	buffs = malloc(sizeof(int) * size);
	if (buffs == NULL)
		return;
	merge_sort_recursive(array, buffs, 0, size);
	free(buffs);
}
