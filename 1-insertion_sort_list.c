#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort algorithm.
 *
 * @list: Pointer to pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *curr, *prev, *temp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    curr = (*list)->next;

    while (curr != NULL)
    {
        prev = curr->prev;
        temp = curr->next;

        while (prev != NULL && prev->n > curr->n)
        {
            if (prev->prev != NULL)
                prev->prev->next = curr;
            if (curr->next != NULL)
                curr->next->prev = prev;

            prev->next = curr->next;
            curr->prev = prev->prev;
            prev->prev = curr;
            curr->next = prev;

            if (curr->prev == NULL)
                *list = curr;

            print_list(*list);

            prev = curr->prev;
        }

        curr = temp;
    }
}
