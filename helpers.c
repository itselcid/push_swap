/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaadi <oessaadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:36:26 by oessaadi          #+#    #+#             */
/*   Updated: 2024/03/01 11:12:21 by oessaadi         ###   ########.fr       */
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

char	*ft_join(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	char	*str;

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
	free((char *)s1);
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
		write(2, "Error\n", 6);
		exit(1);
	}
}
