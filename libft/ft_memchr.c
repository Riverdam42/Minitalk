/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:44:54 by kkawano           #+#    #+#             */
/*   Updated: 2021/08/17 16:51:34 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	size_t				i;

	p = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return ((void *)&p[i]);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// int main(void)
// {
// 	// char *s = (char *)malloc(sizeof(char) + 6);
// 	// int	size = 10;
// 	// int	c = 'z';
// 	// char *p = ft_memchr(s, c, size);
// 	// char *honke = memchr(s, c, size);

// 	// printf("%s\n", p);
// 	// printf("%s\n", honke);
// 	char s[] = {-1, 2, 3, 4, 5,};
// 	printf("本家 = %s\n", memchr(s, -1, 5));
// 	printf("自作 = %s\n", ft_memchr(s, -1, 5));
// }
