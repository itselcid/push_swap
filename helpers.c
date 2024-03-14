/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaadi <oessaadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:36:26 by oessaadi          #+#    #+#             */
/*   Updated: 2024/03/10 22:41:43 by oessaadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **lst)
{
	t_list	*temp;

	if (*lst == NULL)
		return ;
	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
}

void	free_av(char **av, int i)
{
	while (av[i])
	{
		free(av[i]);
		i++;
	}
}

long	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;
	int		digit_count;

	digit_count = 0;
	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && result <= 2147483649)
	{
		result = (result * 10) + str[i++] - '0';
		digit_count++;
	}
	if (str[i] != '\0' || digit_count == 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (sign * result);
}

void	check_empty(char *av, char *str)
{
	int	i;

	i = 0;
	while ((av[i] >= 9 && av[i] <= 13) || av[i] == 32)
		i++;
	if (av[i] == '\0')
	{
		if (str != NULL)
			free(str);
		write(2, "Error\n", 6);
		exit(1);
	}
}

int	init_to_null(char **str, t_list **stack_a, t_list **stack_b)
{
	*str = NULL;
	*stack_a = NULL;
	*stack_b = NULL;
	return (1);
}
