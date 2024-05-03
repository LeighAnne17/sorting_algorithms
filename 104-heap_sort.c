#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @a: First element
 * @b: Second element
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * sift_down - Performs sift-down operation on a heap
 * @array: The array representing the heap
 * @start: The index to start sifting down from
 * @end: The index to stop sifting down at
 * @size: The size of the heap
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
    size_t root = start;
    while (root * 2 + 1 <= end)
    {
        size_t child = root * 2 + 1;
        size_t swap_idx = root;

        if (array[swap_idx] < array[child])
            swap_idx = child;
        if (child + 1 <= end && array[swap_idx] < array[child + 1])
            swap_idx = child + 1;
        if (swap_idx != root)
        {
            swap(&array[root], &array[swap_idx]);
            print_array(array, size);
            root = swap_idx;
        }
        else
        {
            return;
        }
    }
}

/**
 * heapify - Builds a heap from an array
 * @array: The array to be turned into a heap
 * @size: The size of the array
 */
void heapify(int *array, size_t size)
{
    int start = (size - 2) / 2;

    while (start >= 0)
    {
        sift_down(array, start, size - 1, size);
        start--;
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using
 *             the Heap sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    heapify(array, size);
    size_t end = size - 1;

    while (end > 0)
    {
        swap(&array[end], &array[0]);
        print_array(array, size);
        sift_down(array, 0, end - 1, size);
        end--;
    }
}
