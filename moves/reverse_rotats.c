
#include "../push_swap.h"

void reverse_rotate(t_list** head)
{
    t_list* last;
    t_list* current = *head;
	if (*head == NULL || (*head)->next == NULL) 
	{
		return;
	}
    while (current->next->next != NULL) {
        current = current->next;
    }

    last = current->next;
    current->next = NULL;
    last->next = *head;
    *head = last;
}

void rra(t_list** head) 
{
    reverse_rotate(head);
    write(1, "rra\n", 4);
}

void rrb(t_list** head) 
{
    reverse_rotate(head);
    write(1, "rrb\n", 4);
}

void rrr(t_list** a, t_list** b) 
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}
void rrr_bonus(t_list** a, t_list** b) 
{
    reverse_rotate(a);
    reverse_rotate(b);
}