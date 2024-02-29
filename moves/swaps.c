/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaadi <oessaadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:02:04 by oessaadi          #+#    #+#             */
/*   Updated: 2024/02/29 14:08:03 by oessaadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list **stackA)
{
	t_list	*first;
	t_list	*second;

	first = *stackA;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stackA = second;
	write(1, "sa\n", 3);
}

void	sb(t_list **stackB)
{
	t_list	*first;
	t_list	*second;

	first = *stackB;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stackB = second;
	write(1, "sb\n", 3);
}

void	sa_bonus(t_list **stackA)
{
	t_list	*first;
	t_list	*second;

	if (size(*stackA) < 2)
		return ;
	first = *stackA;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stackA = second;
}

void	sb_bonus(t_list **stackB)
{
	t_list	*first ;
	t_list	*second ;
	
	if (size(*stackB) < 2)
		return ;
	first = *stackB;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stackB = second;
}

void	ss_bonus(t_list **stackA, t_list **stackB)
{
	sa_bonus(stackA);
	sb_bonus(stackB);
}
