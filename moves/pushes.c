#include "../push_swap.h"

void pb(Node** stackA, Node** stackB)
{
    if (*stackA == NULL) 
    {
        return;
    }
    Node* temp = *stackA;
    *stackA = (*stackA)->next;
    temp->next = *stackB;
    *stackB = temp;
    write(1, "pb\n", 3);
}
void pa(Node** stackA, Node** stackB) 
{
    if (*stackB == NULL) 
    {
        return;
    }
    Node* temp = *stackB;
    *stackB = (*stackB)->next;
    temp->next = *stackA;
    *stackA = temp;
    write(1, "pa\n", 3);
}