/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaadi <oessaadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:21:20 by oessaadi          #+#    #+#             */
/*   Updated: 2024/02/24 22:50:47 by oessaadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct node
{
	int			data;
	struct node	*next;
}				t_list;

// libft functions
size_t			ft_strlen(const char *s);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
long			ft_atoi(const char *str);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char const *s, char c);
// push_swap functions
void			insertnode(t_list **head, long data);
void			is_sorted_or_double(t_list *stackA);
void			sort_three(t_list **n);
void			check_empty(char *av);
void			free_stack(t_list **lst);
int				size(t_list *stack);
int				max(t_list *stack);
int				min(t_list *stack);
int				index_from_b(int Adata, t_list *stackB);
int				index_from_a(int Bdata, t_list *stackA);
int				best_move(t_list *stackA, t_list *stackB,
					int *index, int index_a);
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