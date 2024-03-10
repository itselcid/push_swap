/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaadi <oessaadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:21:20 by oessaadi          #+#    #+#             */
/*   Updated: 2024/03/10 22:20:07 by oessaadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct node
{
	int			data;
	struct node	*next;
}				t_list;

long			ft_atoi(const char *str);
int				init_to_null(char **str, t_list **stack_a, t_list **stack_b);
char			*ft_join(char *s1, char *s2);
char			**ft_split(char const *s, char c);
void			insertnode(t_list **head, long data, char **argv, int i);
void			is_sorted_or_double(t_list *stackA);
void			sort_three(t_list **n);
void			check_empty(char *av, char *str);
void			free_stack(t_list **lst);
void			free_av(char **av, int i);
int				size(t_list *stack);
int				max(t_list *stack);
int				min(t_list *stack);
int				index_from_b(int Adata, t_list *stackB);
int				index_from_a(int Bdata, t_list *stackA);
int				best_move(t_list *stackA, t_list *stackB, int *index,
					int index_a);
void			push_to_b(t_list **stackA, t_list **stackB, int Adata_to_push,
					int index_to_push_from_A_to_B);
void			handle_first_case(t_list **stackA, t_list **stackB,
					int *index_to_push_from_A_to_B, int *index_b);
void			handle_second_case(t_list **stackA, t_list **stackB,
					int *difference_stackA_indexA,
					int *difference_stackB_indexB);
void			handle_third_case(t_list **stackA, t_list **stackB,
					int *index_to_push_from_A_to_B,
					int *difference_stackB_indexB);
void			handle_fourth_case(t_list **stackA, t_list **stackB,
					int *difference_stackA_indexA, int *index_b);
void			push_to_a(t_list **stackA, t_list **stackB);
void			sort_stack(t_list **stackA, t_list **stackB);
void			rotate_until_sorted(t_list **stackA);

void			sa(t_list **head);
void			sb(t_list **stackB);
void			rotate(t_list **head);
void			reverse_rotate(t_list **head);
void			ra(t_list **head);
void			rb(t_list **head);
void			rr(t_list **a, t_list **b);
void			rra(t_list **head);
void			rrb(t_list **head);
void			rrr(t_list **a, t_list **b);
void			pb(t_list **stackA, t_list **stackB);
void			pa(t_list **stackA, t_list **stackB);

#endif