/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaadi <oessaadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:21:07 by oessaadi          #+#    #+#             */
/*   Updated: 2024/02/25 12:19:26 by oessaadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertnode(t_list **head, long data)
{
	t_list	*newnode;
	t_list	*current;

	if (data < INT_MIN || data > INT_MAX)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	newnode = (t_list *)malloc(sizeof(t_list));
	newnode->data = data;
	newnode->next = NULL;
	if (*head == NULL)
	{
		*head = newnode;
		return ;
	}
	current = *head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = newnode;
}

int	size(t_list *stack)
{
	int		count;
	t_list	*temp;

	count = 0;
	temp = stack;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

void	is_sorted_or_double(t_list *stackA)
{
	t_list	*temp;
	int		sorted;

	sorted = 0;
	while (stackA->next)
	{
		if (stackA->data > stackA->next->data)
			sorted = 1;
		temp = stackA->next;
		while (temp)
		{
			if (stackA->data == temp->data)
			{
				write(1, "Error\n", 6);
				exit(1);
			}
			temp = temp->next;
		}
		stackA = stackA->next;
	}
	if (sorted == 0)
		exit(0);
}

void	sort_three(t_list **n)
{
	int	a;
	int	b;
	int	c;

	a = (*n)->data;
	b = (*n)->next->data;
	c = (*n)->next->next->data;
	if (a > b && a < c)
		sa(n);
	else if (a > b && b > c)
	{
		sa(n);
		rra(n);
	}
	else if (a > c && b < c)
		ra(n);
	else if (a < b && b > c && a > c)
		rra(n);
	else if (a < b && b > c)
	{
		sa(n);
		ra(n);
	}
}

void	free_stack(t_list **lst)
{
	t_list	*temp;

	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
}
