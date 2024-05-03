#include <stdio.h>
#include "sort.h"

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using
 *                    the Quick sort algorithm with Hoare partition scheme
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort_hoare_recursive(array, 0, size - 1, size);
}

/**
 * quicksort_hoare_recursive - Recursively sorts subarray of integers using
 *                              Quick sort algorithm with Hoare partition scheme
 * @array: Array to sort
 * @low: Starting index of the subarray
 * @high: Ending index of the subarray
 * @size: Size of the entire array (for printing)
 */
void quicksort_hoare_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot = partition_hoare(array, low, high, size);
        
        if (pivot != low)
            print_array(array, size);
        
        quicksort_hoare_recursive(array, low, pivot, size);
        quicksort_hoare_recursive(array, pivot + 1, high, size);
    }
}

/**
 * partition_hoare - Partitions the array using the Hoare scheme
 * @array: Array to partition
 * @low: Starting index of the subarray
 * @high: Ending index of the subarray
 * @size: Size of the entire array (for printing)
 *
 * Return: Index of the pivot element
 */
int partition_hoare(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1, j = high + 1;

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        if (i != j)
        {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            print_array(array, size);
        }
    }
}
