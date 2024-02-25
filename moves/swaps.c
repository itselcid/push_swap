#include "../push_swap.h"


void sa(t_list** stackA) 
{
    t_list* first = *stackA;
    t_list* second = first->next;

    first->next = second->next;
    second->next = first;
    *stackA = second;
    write(1, "sa\n", 3);
}
void sb(t_list** stackB)
{
    t_list* first = *stackB;
    t_list* second=first->next;
    
    first->next = second->next;
    second->next = first;
    *stackB = second;
    write(1, "sb\n", 3);
}
void sa_bonus(t_list** stackA) 
{
    t_list* first = *stackA;
    t_list* second = first->next;
    first->next = second->next;
    second->next = first;
    *stackA = second;
}
void sb_bonus(t_list** stackB)
{
	
    t_list* first = *stackB;
    t_list* second=first->next;
    
    first->next = second->next;
    second->next = first;
    *stackB = second;
}