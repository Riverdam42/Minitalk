/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 11:25:40 by kkawano           #+#    #+#             */
/*   Updated: 2021/08/18 23:45:51 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char		*p1;
	const unsigned char		*p2;
	size_t					i;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] && p2[i] && p1[i] == p2[i])
			i++;
		else
			return (p1[i] - p2[i]);
	}
	return (0);
}

// #include <stdio.h>

// int		main(void)
// {
// 	char str1[] = "TOKYO42";
// 	char str2[] = "TOKYH";
// 	char str3[] = "TO";

// 	ft_strncmp(str1, str1, 5);
// 	printf("%s compare %s\n", str1, str1);
// 	printf("%d\n", ft_strncmp(str1, str1, 5));
// 	ft_strncmp(str1, str2, 4);
// 	printf("%s compare %s\n", str1, str2);
// 	printf("%d\n", ft_strncmp(str1, str2, 4));
// 	ft_strncmp(str1, str3, 2);
// 	printf("%s compare %s\n", str1, str3);
// 	printf("%d\n", ft_strncmp(str1, str3, 2));
// 	return (0);
// }
