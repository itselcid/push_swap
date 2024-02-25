#include "../push_swap.h"

void pb(t_list** stackA, t_list** stackB)
{
    if (*stackA == NULL) 
    {
        return;
    }
    t_list* temp = *stackA;
    *stackA = (*stackA)->next;
    temp->next = *stackB;
    *stackB = temp;
    write(1, "pb\n", 3);
}
void pa(t_list** stackA, t_list** stackB) 
{
    if (*stackB == NULL) 
    {
        return;
    }
    t_list* temp = *stackB;
    *stackB = (*stackB)->next;
    temp->next = *stackA;
    *stackA = temp;
    write(1, "pa\n", 3);
}
void pb_bonus(t_list** stackA, t_list** stackB)
{
    if (*stackA == NULL ) 
    {
        return;
    }
    t_list* temp = *stackA;
    *stackA = (*stackA)->next;
    temp->next = *stackB;
    *stackB = temp;
}
void pa_bonus(t_list** stackA, t_list** stackB) 
{
    if (*stackB == NULL) 
    {
        return;
    }
    t_list* temp = *stackB;
    *stackB = (*stackB)->next;
    temp->next = *stackA;
    *stackA = temp;
}