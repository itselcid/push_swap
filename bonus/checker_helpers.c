/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaadi <oessaadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:11:05 by oessaadi          #+#    #+#             */
/*   Updated: 2024/03/14 02:10:05 by oessaadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	is_sorted(t_list *stackA, t_list *stackB)
{
	int	sorted;
	t_list *tmp;

	if (stackA == NULL)
	{
		write(1, "KO\n", 3);
		free_stack (&stackB);
		exit(0);
	}
	sorted = 0;
	tmp = stackA;
	while (stackA->next)
	{
		if (stackA->data > stackA->next->data)
			sorted = 1;
		stackA = stackA->next;
	}
	if (sorted == 0 && stackB == NULL)
	{
		write(1, "OK\n", 3);
		free_stack(&tmp);
		free_stack(&stackB);
		exit(0);
	}
}

void	check_double(t_list *stackA)
{
	t_list	*temp;
	t_list	*courent;

	courent = stackA;
	while (courent->next)
	{
		temp = courent->next;
		while (temp)
		{
			if (courent->data == temp->data)
			{
				free_stack(&stackA);
				write(2, "Error\n", 6);
				exit(1);
			}
			temp = temp->next;
		}
		courent = courent->next;
	}
}
