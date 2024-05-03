#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * merge - Merges two subarrays of arr[]
 * @arr: The array to be sorted
 * @left: Index of the left subarray
 * @middle: Index of the middle of the array
 * @right: Index of the right subarray
 */
void merge(int *arr, size_t left, size_t middle, size_t right)
{
    size_t i, j, k;
    size_t n1 = middle - left + 1;
    size_t n2 = right - middle;

    /* Create temporary arrays */
    int *L = malloc(sizeof(int) * n1);
    int *R = malloc(sizeof(int) * n2);
    if (L == NULL || R == NULL)
    {
        free(L);
        free(R);
        return;
    }

    /* Copy data to temporary arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    /* Merge the temporary arrays back into arr[left..right] */
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    /* Print the merged array */
    printf("[Done]:");
    print_array(arr + left, right - left + 1);

    /* Free temporary arrays */
    free(L);
    free(R);
}

/**
 * merge_sort_recursive - Recursive function to perform merge sort
 * @array: The array to be sorted
 * @left: Index of the left subarray
 * @right: Index of the right subarray
 */
void merge_sort_recursive(int *array, size_t left, size_t right)
{
    if (left < right)
    {
        size_t middle = left + (right - left) / 2;

        /* Sort first and second halves */
        merge_sort_recursive(array, left, middle);
        merge_sort_recursive(array, middle + 1, right);

        /* Merge the sorted halves */
        merge(array, left, middle, right);
    }
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 *              the Merge sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    printf("Merging...\n");
    merge_sort_recursive(array, 0, size - 1);
}
