#include "../push_swap.h"

void rotate(t_list** head)
{
    t_list* first = *head;
    t_list* current = *head;

	if (*head == NULL || (*head)->next == NULL) 
	{
		return;
	}

    while (current->next != NULL) {
        current = current->next;
    }

    *head = first->next;
    first->next = NULL;
    current->next = first;
}

void ra(t_list** head) 
{
    rotate(head);
    write(1, "ra\n", 3);
}

void rb(t_list** head) 
{
    rotate(head);
    write(1, "rb\n", 3);
}

void rr(t_list** a, t_list** b) 
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}
void rr_bonus(t_list** a, t_list** b) 
{
    rotate(a);
    rotate(b);
}
