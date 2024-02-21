/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaadi <oessaadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:21:07 by oessaadi          #+#    #+#             */
/*   Updated: 2024/02/21 11:37:10 by oessaadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertNode(Node **head, int data)
{
	Node	*newNode;
	Node	*current;

	newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	if (*head == NULL)
	{
		*head = newNode;
		return ;
	}
	current = *head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = newNode;
}
int	size(Node *stack)
{
	int		count;
	Node	*temp;

	count = 0;
	temp = stack;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
void	is_sorted(Node **stackA)
{
	Node	*temp;

	temp = *stackA;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
		{
			printf("stackA is not sorted\n");
			return ;
		}
		temp = temp->next;
	}
	printf("stackA is sorted\n");
}
void	displayList(Node *head)
{
	Node	*current;

	current = head;
	while (current != NULL)
	{
		printf("%d \n", current->data);
		current = current->next;
	}
}

void	sort_three(Node **n)
{
	int a;
	int b;
	int c;

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