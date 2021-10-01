/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:38:05 by kkawano           #+#    #+#             */
/*   Updated: 2021/08/16 01:10:40 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;

	d = (unsigned char *)dest;
	s = (unsigned const char *)src;
	if (!dest && !src)
		return (NULL);
	if (!n)
		return (dest);
	if (dest < src)
	{
		while (n--)
			*d++ = *s++;
	}
	else if (dest > src)
	{
		while (n--)
			d[n] = s[n];
	}
	return (dest);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char s[] = {65, 66, 67, 68, 69, 0, 45};
// 	char s0[] = { 0,  0,  0,  0,  0,  0, 0};

// 	printf("s0 == %s\n", ft_memmove(s0, s, 7));
// 	return (0);
// }

// int	main(void)
// {
// 	char str[10] = "12345678";
// 	char str2[10] = "12345678";

// 	memmove(&str[0], &str[], 5);
// 	printf("本家 = %s\n", str);
// 	printf("\n");
// 	ft_memmove(&str2[0], &str2[2], 5);
// 	printf("自作 = %s\n ", str2);
// }
