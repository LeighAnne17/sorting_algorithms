#include <stdio.h>
#include "sort.h"

/**
 * bitonic_merge - Merges two arrays in a bitonic sequence
 * @array: Pointer to the array to sort
 * @low: Lower bound index of the array
 * @count: Number of elements to merge
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
    if (count > 1)
    {
        size_t k = count / 2;
        for (size_t i = low; i < low + k; i++)
        {
            if ((array[i] > array[i + k]) == dir)
            {
                int temp = array[i];
                array[i] = array[i + k];
                array[i + k] = temp;
            }
        }
        bitonic_merge(array, low, k, dir);
        bitonic_merge(array, low + k, k, dir);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using
 *                the Bitonic sort algorithm
 * @array: Pointer to the array to sort
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (size < 2)
        return;

    for (size_t k = 2; k <= size; k *= 2)
    {
        for (size_t j = k / 2; j > 0; j /= 2)
        {
            for (size_t i = 0; i < size; i += k)
            {
                bitonic_merge(array, i, j, 1);
                bitonic_merge(array, i + j, j, 0);
                printf("Merging [%lu/%lu] (UP):\n", j, k);
                print_array(array, size);
            }
        }
    }
}
