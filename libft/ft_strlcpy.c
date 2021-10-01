/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 18:19:20 by kkawano           #+#    #+#             */
/*   Updated: 2021/08/17 22:31:31 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len + 1 < dstsize)
		ft_memcpy(dst, src, src_len + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (src_len);
}

// #include <stdio.h>

// size_t ft_strlcpy (char *dst, const char *src, size_t dstsize)
// {
// 	size_t i;
// 	size_t src_len;

// 	if (!dst || !src)
// 		return (0);
// 	src_len = ft_strlen(src);
// 	i = 0;
// 	while (i < dstsize - 1 && i <= src_len)
// 	{
// 			dst[i] = src[i];
// 			i++;
// 	}
// 	if (dstsize != 0)
// 		dst[i] = '\0';
// 	return (src_len);
// }

// int		main(void)
// {
// 	printf("自作 = %zu\n", ft_strlcpy(NULL, NULL, 5));
// 	// printf("本家 = %lu\n", strlcpy(NULL, NULL, 5));
// }
