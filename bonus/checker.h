/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaadi <oessaadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:12:30 by oessaadi          #+#    #+#             */
/*   Updated: 2024/03/09 15:13:10 by oessaadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct node
{
	int			data;
	struct node	*next;
}				t_list;

// checker functions
long			ft_atoi(const char *str);
int				init_to_null(char **str);
void			insertnode(t_list **head, long data, char **argv, int i);
void			is_sorted(t_list *stackA, t_list *stackB);
void			check_double(t_list *stackA);
void			checker(t_list **stack_a, t_list **stack_b);
void			execute_command(char *line, t_list **stack_a, t_list **stack_b);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_join(char *s1, char *s2);
char			**ft_split(char const *s, char c);
void			check_empty(char *av, char *str);
void			free_stack(t_list **lst);
void			free_av(char **av, int i);

void			sa_bonus(t_list **head);
void			sb_bonus(t_list **stackB);
void			pb_bonus(t_list **stackA, t_list **stackB);
void			pa_bonus(t_list **stackA, t_list **stackB);
void			rotate(t_list **head);
void			reverse_rotate(t_list **head);
void			rr_bonus(t_list **a, t_list **b);
void			rrr_bonus(t_list **a, t_list **b);
void			ss_bonus(t_list **stackA, t_list **stackB);

// get_next_line functions

char			*get_next_line(int fd);
char			*ft_line(char *str);
char			*ft_rest(char *str);
char			*ft_strjoin(char *s1, char *s2);
size_t			ft_strlen(const char *s);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strchr(const char *s, int c);
char			*handle_eof(int chars_readed, char *rest);
char			*handle_line(char *rest);

#endif