#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @list: Pointer to the head of the list
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
    if (*list == NULL || a == NULL || b == NULL)
        return;

    if (a->prev != NULL)
        a->prev->next = b;
    else
        *list = b;

    if (b->next != NULL)
        b->next->prev = a;

    a->next = b->next;
    b->prev = a->prev;
    b->next = a;
    a->prev = b;

    print_list(*list);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list in ascending order
 *                      using Cocktail shaker sort algorithm
 *
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped;
    listint_t *current;

    if (list == NULL || *list == NULL)
        return;

    do {
        swapped = 0;
        for (current = *list; current->next != NULL; current = current->next)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, current, current->next);
                swapped = 1;
            }
        }
        if (!swapped)
            break;
        swapped = 0;
        for (; current->prev != NULL; current = current->prev)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(list, current->prev, current);
                swapped = 1;
            }
        }
    } while (swapped);
}
