#include <stdlib.h>
#include "deck.h"

/**
 * compare_cards - Compare two card pointers
 * @card1: Pointer to the first card
 * @card2: Pointer to the second card
 *
 * Return: Negative value if card1 should go before card2,
 *         Positive value if card2 should go before card1,
 *         Zero if the cards are equal.
 */
int compare_cards(const void *card1, const void *card2)
{
    const card_t *c1 = *((const card_t **)card1);
    const card_t *c2 = *((const card_t **)card2);

    if (c1->kind != c2->kind)
        return c1->kind - c2->kind;
    else
        return strcmp(c1->value, c2->value);
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
    size_t deck_size = 52;
    deck_node_t *current = *deck;
    card_t *cards[52];

    // Store pointers to all cards in an array
    for (size_t i = 0; i < deck_size; i++)
    {
        cards[i] = (card_t *)current->card;
        current = current->next;
    }

    // Sort the array of card pointers using qsort
    qsort(cards, deck_size, sizeof(card_t *), compare_cards);

    // Update the deck with the sorted cards
    current = *deck;
    for (size_t i = 0; i < deck_size; i++)
    {
        current->card = cards[i];
        current = current->next;
    }
}
