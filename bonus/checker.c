/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaadi <oessaadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:54:48 by oessaadi          #+#    #+#             */
/*   Updated: 2024/02/26 11:54:32 by oessaadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void checker(t_list **stack_a, t_list **stack_b)
{
	char	*line = NULL;
	
	line = get_next_line(0);

	while (line)
	{
		if (ft_strncmp(line, "sa\n", 3) == 0)
			sa_bonus(stack_a);
		else if (ft_strncmp(line, "sb\n", 3) == 0)
			sb_bonus(stack_b);
		else if (ft_strncmp(line, "pa\n", 3) == 0)
			pa_bonus(stack_a, stack_b);
		else if (ft_strncmp(line, "pb\n", 3) == 0)
			pb_bonus(stack_a, stack_b);
		else if (ft_strncmp(line, "ra\n", 3) == 0)
			rotate(stack_a);
		else if (ft_strncmp(line, "rb\n", 3) == 0)
			rotate(stack_b);
		else if (ft_strncmp(line, "rr\n", 3) == 0)
			rr_bonus(stack_a, stack_b);
		else if (ft_strncmp(line, "rra\n", 4) == 0)
			reverse_rotate(stack_a);
		else if (ft_strncmp(line, "rrb\n", 4) == 0)
			reverse_rotate(stack_b);
		else if (ft_strncmp(line, "rrr\n", 4) == 0)
			rrr_bonus(stack_a, stack_b);
		else
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		line = get_next_line(0);
	}
	is_sorted(*stack_a, *stack_b);
	write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
		t_list	*stack_a= NULL;
		t_list	*stack_b	= NULL;
	int		i;
	char	*str;

	if (argc == 1)
		return (0);
	i = 1;
	while (i < argc)
	{
		check_empty(argv[i]);
		str = ft_join(str, argv[i++]);
	}
	argv = ft_split(str, ' ');
	i = 0;
	while (argv[i])
		insertnode(&stack_a, ft_atoi(argv[i++]));
	check_double(stack_a);
	 checker(&stack_a,&stack_b);
	 free_stack(&stack_a);
	 free_stack(&stack_b);
	 
}