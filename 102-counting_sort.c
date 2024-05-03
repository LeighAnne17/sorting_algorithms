#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm
 *
 * @array: The array of integers to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    /* Find the maximum value in the array */
    int max = array[0];
    for (size_t i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    /* Create a counting array with size max + 1 */
    int *count = malloc(sizeof(int) * (max + 1));
    if (count == NULL)
        return;

    /* Initialize counting array elements to 0 */
    for (int i = 0; i <= max; i++)
        count[i] = 0;

    /* Count occurrences of each element in the array */
    for (size_t i = 0; i < size; i++)
        count[array[i]]++;

    /* Print the counting array */
    printf("%d", count[0]);
    for (int i = 1; i <= max; i++)
        printf(", %d", count[i]);
    printf("\n");

    /* Modify the counting array to store cumulative frequencies */
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    /* Build the sorted array */
    int *sorted = malloc(sizeof(int) * size);
    if (sorted == NULL) {
        free(count);
        return;
    }

    for (int i = size - 1; i >= 0; i--) {
        sorted[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    /* Copy the sorted array back to the original array */
    for (size_t i = 0; i < size; i++)
        array[i] = sorted[i];

    /* Free allocated memory */
    free(count);
    free(sorted);
}
