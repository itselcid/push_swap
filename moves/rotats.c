#include "../push_swap.h"

void rotate(Node** head)
{
    Node* first = *head;
    Node* current = *head;

    while (current->next != NULL) {
        current = current->next;
    }

    *head = first->next;
    first->next = NULL;
    current->next = first;
}

void ra(Node** head) 
{
    rotate(head);
    write(1, "ra\n", 3);
}

void rb(Node** head) 
{
    rotate(head);
    write(1, "rb\n", 3);
}

void rr(Node** a, Node** b) 
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}
