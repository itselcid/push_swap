/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaadi <oessaadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:21:07 by oessaadi          #+#    #+#             */
/*   Updated: 2024/03/10 22:55:26 by oessaadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertnode(t_list **head, long data, char **argv, int i)
{
	t_list	*newnode;
	t_list	*current;

	if (data < INT_MIN || data > INT_MAX)
	{
		free_stack(head);
		free_av(argv, i);
		write(2, "Error\n", 6);
		exit(1);
	}
	newnode = (t_list *)malloc(sizeof(t_list));
	newnode->data = data;
	newnode->next = NULL;
	if (*head == NULL)
	{
		*head = newnode;
		return (free(argv[i]));
	}
	current = *head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = newnode;
	free(argv[i]);
}

void double_found(t_list *stack_a)
{
			free_stack(&stack_a);
			write(2, "Error\n", 6);
			exit(1);
}
void	is_sorted_or_double(t_list *stackA, char **argv)
{
	t_list	*temp;
	int		sorted;
	t_list	*stackA_head;

	stackA_head = stackA;
	free(argv);
	sorted = 0;
	while (stackA->next)
	{
		if (stackA->data > stackA->next->data)
			sorted = 1;
		temp = stackA->next;
		while (temp)
		{
			if (stackA->data == temp->data)
				double_found(stackA_head);
			temp = temp->next;
		}
		stackA = stackA->next;
	}
	if (sorted == 0)
		free_exit(&stackA_head);
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

int	max(t_list *stack)
{
	int	max;
	int	max_index;
	int	i;

	max = stack->data;
	max_index = 0;
	i = 0;
	while (stack != NULL)
	{
		if (stack->data > max)
		{
			max = stack->data;
			max_index = i;
		}
		i++;
		stack = stack->next;
	}
	return (max_index);
}
