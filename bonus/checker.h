#ifndef CHECKER_H
# define CHECKER_H

# include "../get_next_line.h"


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

// libft functions
size_t			ft_strlen(const char *s);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
long			ft_atoi(const char *str);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char const *s, char c);
// checker functions
void			insertnode(t_list **head, long data);
void			is_sorted_or_double_bonus(t_list *stackA,t_list *stackB);
void			checker(t_list **stack_a, t_list **stack_b);


void			sa(t_list **head);
void			sb(t_list **stackB);
void			rotate(t_list **head);
void			reverse_rotate(t_list **head);
void			pb_bonus(t_list **stackA, t_list **stackB);
void			pa_bonus(t_list **stackA, t_list **stackB);
void 			rr_bonus(t_list** a, t_list** b);
void 			rrr_bonus(t_list** a, t_list** b);

#endif