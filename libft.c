/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaadi <oessaadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 21:36:45 by oessaadi          #+#    #+#             */
/*   Updated: 2024/02/25 16:38:27 by oessaadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	len;

// 	len = 0;
// 	while (s[len])
// 		len++;
// 	return (len);
// }

// size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	srclen;
// 	size_t	dstlen;
// 	size_t	i;

// 	if (dstsize == 0 && dst == NULL)
// 		return (ft_strlen(src));
// 	srclen = ft_strlen(src);
// 	dstlen = ft_strlen(dst);
// 	if (dstsize <= dstlen)
// 		return (dstsize + srclen);
// 	i = 0;
// 	while (src[i] && (dstlen + i < dstsize - 1))
// 	{
// 		dst[dstlen + i] = src[i];
// 		i++;
// 	}
// 	dst[dstlen + i] = '\0';
// 	return (dstlen + srclen);
// }

// size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	srclen;
// 	size_t	i;

// 	srclen = 0;
// 	i = 0;
// 	while (src[srclen])
// 	{
// 		srclen++;
// 	}
// 	if (dstsize == 0)
// 		return (srclen);
// 	while (src[i] && i < dstsize - 1)
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// 	return (srclen);
// }

// char	*ft_strdup(const char *s1)
// {
// 	int		len;
// 	char	*p;
// 	int		i;

// 	len = ft_strlen(s1);
// 	p = (char *)malloc((len + 1) * sizeof(char));
// 	if (p == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (i < len)
// 	{
// 		p[i] = s1[i];
// 		i++;
// 	}
// 	p[i] = '\0';
// 	return (p);
// }
