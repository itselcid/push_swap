/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaadi <oessaadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:07:40 by oessaadi          #+#    #+#             */
/*   Updated: 2024/02/21 13:53:12 by oessaadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(Node *stack)
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

int	min(Node *stack)
{
	Node	*temp;
	int		min;
	int		min_index;
	int		i;

	temp = stack;
	min = temp->data;
	min_index = 0;
	i = 0;
	while (temp != NULL)
	{
		if (temp->data < min)
		{
			min = temp->data;
			min_index = i;
		}
		i++;
		temp = temp->next;
	}
	return (min_index);
}

int	max_of_2_elements(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	index_from_b(int Adata, Node *stackB)
{
	int		index;
	int		i;
	int		l9rib;
	Node	*temp;

	index = -1;
	i = 0;
	l9rib = -555555;
	temp = stackB;
	while (stackB)
	{
		if (stackB->data < Adata && stackB->data > l9rib)
		{
			l9rib = stackB->data;
			index = i;
		}
		stackB = stackB->next;
		i++;
	}
	if (index == -1)
		index = max(temp);
	return (index);
}

int calculate_moves(int index_a, int index_b, Node* stackA, Node* stackB)
{
    int moves = 0;
    if (index_a <= size(stackA) / 2 && index_b <= size(stackB) / 2)
        moves = max_of_2_elements(index_a, index_b);
    else if (index_a > size(stackA) / 2 && index_b > size(stackB) / 2)
        moves = max_of_2_elements(size(stackA) - index_a, size(stackB) - index_b);
    else if (index_a <= size(stackA) / 2 && index_b > size(stackB) / 2)
        moves = index_a + (size(stackB) - index_b);
    else if (index_a > size(stackA) / 2 && index_b <= size(stackB) / 2)
        moves = index_b + (size(stackA) - index_a);
    return moves;
}

int best_move(Node* stackA, Node* stackB,int* index)
{
    int index_a ;
    int least_moves ;
    int data_with_least_moves ;
    Node* tempA = stackA;

	index_a = 0
	least_moves = INT_MAX;
    while (tempA)
    {
        int index_b = index_from_b(tempA->data, stackB);
        int moves = calculate_moves(index_a, index_b, stackA, stackB);
        if (least_moves > moves)
        {
            least_moves = moves;
            data_with_least_moves = tempA->data;
            *index = index_a;
        }
        index_a++;
        tempA = tempA->next;
    }
    return data_with_least_moves;
}
