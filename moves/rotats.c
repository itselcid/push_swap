#include "../push_swap.h"

void ra(Node** head) 
{
    Node* first = *head;
    Node* current = *head;

    while (current->next != NULL) {
        current = current->next;
    }

    *head = first->next;
    first->next = NULL;
    current->next = first;
    write(1, "ra\n", 3);
}

void rra(Node** head) 
{
    Node* last;
    Node* current = *head;

    while (current->next->next != NULL) {
        current = current->next;
    }

    last = current->next;
    current->next = NULL;
    last->next = *head;
    *head = last;
    write(1, "rra\n", 4);
}