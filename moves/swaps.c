#include "../push_swap.h"

void sa(Node** stackA) 
{
    Node* first = *stackA;
    Node* second = first->next;

    first->next = second->next;
    second->next = first;
    *stackA = second;
    write(1, "sa\n", 3);
}
void sb(Node** stackB)
{
    Node* first = *stackB;
    Node* second=first->next;
    
    first->next = second->next;
    second->next = first;
    *stackB = second;
    write(1, "sb\n", 3);
}