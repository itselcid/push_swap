/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaadi <oessaadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:07:40 by oessaadi          #+#    #+#             */
/*   Updated: 2024/02/24 22:14:10 by oessaadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_of_2_elements(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	index_from_b(int Adata, t_list *stackB)
{
	int		index;
	int		i;
	int		l9rib;
	t_list	*temp;

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

int	calculate_moves(int index_a, int index_b, t_list *stackA, t_list *stackB)
{
	int	moves;

	moves = 0;
	if (index_a <= size(stackA) / 2 && index_b <= size(stackB) / 2)
		moves = max_of_2_elements(index_a, index_b);
	else if (index_a > size(stackA) / 2 && index_b > size(stackB) / 2)
		moves = max_of_2_elements(size(stackA) - index_a, size(stackB)
				- index_b);
	else if (index_a <= size(stackA) / 2 && index_b > size(stackB) / 2)
		moves = index_a + (size(stackB) - index_b);
	else if (index_a > size(stackA) / 2 && index_b <= size(stackB) / 2)
		moves = index_b + (size(stackA) - index_a);
	return (moves);
}

int	best_move(t_list *stackA, t_list *stackB, int *index, int index_a)
{
	int		least_moves;
	int		data_with_least_moves;
	t_list	*temp_a;
	int		index_b;
	int		moves;

	temp_a = stackA;
	index_a = 0;
	least_moves = INT_MAX;
	while (temp_a)
	{
		index_b = index_from_b(temp_a->data, stackB);
		moves = calculate_moves(index_a, index_b, stackA, stackB);
		if (least_moves > moves)
		{
			least_moves = moves;
			data_with_least_moves = temp_a->data;
			*index = index_a;
		}
		index_a++;
		temp_a = temp_a->next;
	}
	return (data_with_least_moves);
}
