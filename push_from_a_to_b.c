/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_from_a_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaadi <oessaadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:03:15 by oessaadi          #+#    #+#             */
/*   Updated: 2024/02/25 16:06:54 by oessaadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_first_case(t_list **stackA, t_list **stackB,
		int *index_to_push_from_A_to_B, int *index_b)
{
	while (*index_to_push_from_A_to_B > 0 && *index_b > 0)
	{
		rr(stackA, stackB);
		(*index_to_push_from_A_to_B)--;
		(*index_b)--;
	}
	while (*index_to_push_from_A_to_B > 0)
	{
		ra(stackA);
		(*index_to_push_from_A_to_B)--;
	}
	while (*index_b > 0)
	{
		rb(stackB);
		(*index_b)--;
	}
}

void	handle_second_case(t_list **stackA, t_list **stackB,
		int *difference_stacka_indexa, int *difference_stackb_indexb)
{
	while (*difference_stacka_indexa > 0 && *difference_stackb_indexb > 0)
	{
		rrr(stackA, stackB);
		(*difference_stacka_indexa)--;
		(*difference_stackb_indexb)--;
	}
	while (*difference_stacka_indexa > 0)
	{
		rra(stackA);
		(*difference_stacka_indexa)--;
	}
	while (*difference_stackb_indexb > 0)
	{
		rrb(stackB);
		(*difference_stackb_indexb)--;
	}
}

void	handle_third_case(t_list **stackA, t_list **stackB,
		int *index_to_push_from_A_to_B, int *difference_stackb_indexb)
{
	while (*index_to_push_from_A_to_B > 0)
	{
		ra(stackA);
		(*index_to_push_from_A_to_B)--;
	}
	while (*difference_stackb_indexb > 0)
	{
		rrb(stackB);
		(*difference_stackb_indexb)--;
	}
}

void	handle_fourth_case(t_list **stackA, t_list **stackB,
		int *difference_stacka_indexa, int *index_b)
{
	while (*difference_stacka_indexa > 0)
	{
		rra(stackA);
		(*difference_stacka_indexa)--;
	}
	while (*index_b > 0)
	{
		rb(stackB);
		(*index_b)--;
	}
}

void	push_to_b(t_list **stackA, t_list **stackB, int Adata_to_push,
		int index_to_push_from_A_to_B)
{
	int	index_b;
	int	difference_stacka_indexa;
	int	difference_stackb_indexb;

	index_b = index_from_b(Adata_to_push, *stackB);
	difference_stacka_indexa = size(*stackA) - index_to_push_from_A_to_B;
	difference_stackb_indexb = size(*stackB) - index_b;
	if (index_to_push_from_A_to_B <= size(*stackA) / 2
		&& index_b <= size(*stackB) / 2)
		handle_first_case(stackA, stackB, &index_to_push_from_A_to_B, &index_b);
	if (index_to_push_from_A_to_B > size(*stackA) / 2 && index_b > size(*stackB)
		/ 2)
		handle_second_case(stackA, stackB, &difference_stacka_indexa,
			&difference_stackb_indexb);
	if (index_to_push_from_A_to_B <= size(*stackA) / 2
		&& index_b > size(*stackB) / 2)
		handle_third_case(stackA, stackB, &index_to_push_from_A_to_B,
			&difference_stackb_indexb);
	if (index_to_push_from_A_to_B > size(*stackA) / 2
		&& index_b <= size(*stackB) / 2)
		handle_fourth_case(stackA, stackB, &difference_stacka_indexa, &index_b);
}
