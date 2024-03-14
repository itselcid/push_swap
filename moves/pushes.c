/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaadi <oessaadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:51:50 by oessaadi          #+#    #+#             */
/*   Updated: 2024/03/14 02:11:42 by oessaadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(t_list **stackA, t_list **stackB)
{
	t_list	*temp;

	if (*stackA == NULL)
	{
		return ;
	}
	temp = *stackA;
	*stackA = (*stackA)->next;
	temp->next = *stackB;
	*stackB = temp;
	write(1, "pb\n", 3);
}

void	pa(t_list **stackA, t_list **stackB)
{
	t_list	*temp;

	if (*stackB == NULL)
	{
		return ;
	}
	temp = *stackB;
	*stackB = (*stackB)->next;
	temp->next = *stackA;
	*stackA = temp;
	write(1, "pa\n", 3);
}

void	pb_bonus(t_list **stackA, t_list **stackB)
{
	t_list	*temp;

	if (*stackA == NULL)
	{
		return ;
	}
	temp = *stackA;
	*stackA = (*stackA)->next;
	temp->next = *stackB;
	*stackB = temp;
}

void	pa_bonus(t_list **stackA, t_list **stackB)
{
	t_list	*temp;

	if (*stackB == NULL)
		return ;
	temp = *stackB;
	*stackB = (*stackB)->next;
	temp->next = *stackA;
	*stackA = temp;
}
