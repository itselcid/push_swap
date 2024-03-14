/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaadi <oessaadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:12:13 by oessaadi          #+#    #+#             */
/*   Updated: 2024/03/09 15:12:17 by oessaadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	free_exit(t_list **stackA)
{
    free_stack(stackA);
    exit(0);
}
char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

int	len(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*p;

	j = 0;
	i = 0;
	if (s1 == NULL)
	{
		p = malloc(len(s2) + 1);
		ft_strcpy(p, s2);
		return (p);
	}
	p = malloc(len(s1) + len(s2) + 2);
	if (p == NULL)
		return (0);
	while (s1[j])
		p[i++] = s1[j++];
	j = 0;
	p[i] = ' ';
	i++;
	while (s2[j])
		p[i++] = s2[j++];
	p[i] = '\0';
	free(s1);
	return (p);
}
