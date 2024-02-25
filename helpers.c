/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaadi <oessaadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:36:26 by oessaadi          #+#    #+#             */
/*   Updated: 2024/02/25 16:41:11 by oessaadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	min(t_list *stack)
{
	t_list	*temp;
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

long	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i++] - '0';
	}
	if (str[i] != '\0')
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	return (sign * result);
}

char *ft_join(char const *s1, char const *s2)
{
    int i ;
	int j ;
	int k ;
    char *str;

	i = 0;
	j = 0;
    while (s1 && s1[i])
			 i++;
    while (s2 && s2[j])
			 j++;
    str = (char *)malloc(sizeof(char) * (i + j + 2));
    if (str == NULL)
        return (NULL);
	k = 0;
    i = 0;
    while (s1 && s1[i])
        str[k++] = s1[i++];
    str[k++] = ' ';
    j = 0;
    while (s2 && s2[j])
        str[k++] = s2[j++];
    str[k] = '\0';
    return (str);
}
void	check_empty(char *av)
{
	int	i;

	i = 0;
	while ((av[i] >= 9 && av[i] <= 13) || av[i] == 32)
		i++;
	if (av[i] == '\0')
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}
