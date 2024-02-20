
#include "../push_swap.h"

void reverse_rotate(Node** head)
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
}

void rra(Node** head) 
{
    reverse_rotate(head);
    write(1, "rra\n", 4);
}

void rrb(Node** head) 
{
    reverse_rotate(head);
    write(1, "rrb\n", 4);
}

void rrr(Node** a, Node** b) 
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}