/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaadi <oessaadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:36:26 by oessaadi          #+#    #+#             */
/*   Updated: 2024/02/24 22:13:14 by oessaadi         ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total;
	char	*str;

	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	total = ft_strlen(s1) + ft_strlen(s2) + 2;
	str = (char *)malloc(sizeof(char) * total);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, total);
	ft_strlcat(str, " ", total);
	ft_strlcat(str, s2, total);
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
