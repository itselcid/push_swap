/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaadi <oessaadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:44:22 by oessaadi          #+#    #+#             */
/*   Updated: 2024/03/10 21:48:12 by oessaadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_from_a(int Bdata, t_list *stack_a)
{
	int		index;
	int		i;
	int		l9rib_lkbir;
	t_list	*temp;

	index = -1;
	i = 0;
	l9rib_lkbir = INT_MAX;
	temp = stack_a;
	while (stack_a)
	{
		if (stack_a->data > Bdata && stack_a->data <= l9rib_lkbir)
		{
			l9rib_lkbir = stack_a->data;
			index = i;
		}
		stack_a = stack_a->next;
		i++;
	}
	if (index == -1)
		index = min(temp);
	return (index);
}

void	push_to_a(t_list **stack_a, t_list **stackB)
{
	int	index_a;
	int	difference_stacka_indexa;

	while (*stackB)
	{
		index_a = index_from_a((*stackB)->data, *stack_a);
		difference_stacka_indexa = size(*stack_a) - index_a;
		if (index_a <= size(*stack_a) / 2)
			while (index_a-- > 0)
				ra(stack_a);
		else if (index_a > size(*stack_a) / 2)
			while (difference_stacka_indexa-- > 0)
				rra(stack_a);
		pa(stack_a, stackB);
	}
}

void	rotate_until_sorted(t_list **stack_a)
{
	int	index;
	int	difference_stacka_indexa;

	index = min(*stack_a);
	difference_stacka_indexa = size(*stack_a) - index;
	if (index <= size(*stack_a) / 2)
		while (index-- > 0)
			ra(stack_a);
	else if (index > size(*stack_a) / 2)
		while (difference_stacka_indexa-- > 0)
			rra(stack_a);
}

void	sort_stack(t_list **stack_a, t_list **stackB)
{
	int	index_to_push_from_a_to_b;
	int	data_with_least_moves;
	int	index_a;

	index_a = 0;
	if (size(*stack_a) > 3)
		pb(stack_a, stackB);
	if (size(*stack_a) > 3)
		pb(stack_a, stackB);
	while (size(*stack_a) > 3)
	{
		data_with_least_moves = best_move(*stack_a, *stackB,
				&index_to_push_from_a_to_b, index_a);
		push_to_b(stack_a, stackB, data_with_least_moves,
			index_to_push_from_a_to_b);
		pb(stack_a, stackB);
	}
	sort_three(stack_a);
	push_to_a(stack_a, stackB);
	rotate_until_sorted(stack_a);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	char	*str;

	if (init_to_null(&str) && argc == 1)
		return (0);
	i = 1;
	while (i < argc)
	{
		check_empty(argv[i], str);
		str = ft_join(str, argv[i++]);
	}
	argv = ft_split(str, ' ');
	i = -1;
	while (argv[++i])
		insertnode(&stack_a, ft_atoi(argv[i]), argv, i);
	is_sorted_or_double(stack_a);
	if (size(stack_a) == 2)
		sa(&stack_a);
	else if (size(stack_a) == 3)
		sort_three(&stack_a);
	else
		sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
}
