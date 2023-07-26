Project Title: 0x1B. C - Sorting algorithms & Big O
project done by Olabanji Enioluwayan.
Resources
I Read and watch

Sorting algorithm
Big O notation
Sorting algorithms animations
15 sorting algorithms in 6 minutes
CS50 Algorithms explanation in detail by David Malan
All about sorting algorithms

GENERAL
At least four different sorting algorithms
What is the Big O notation, and how to evaluate the time complexity of an algorithm
How to select the best sorting algorithm for a given input
What is a stable sorting algorithm
TASKS:

Bubble sort
Insertion sort
Selection sort
Quick sort
Shell sort - Knuth Sequence
Cocktail shaker sort
Counting sort
Merge sort
Heap sort
Radix sort
Bitonic sort
Quick Sort - Hoare Partition scheme
Dealer
Data Structure and Functions
print_list

#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
    int i;

    i = 0;
    while (list)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        ++i;
        list = list->next;
    }
    printf("\n");
}
print_array

#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
