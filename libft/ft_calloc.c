/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 00:45:28 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/02 00:45:30 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	str = (void *)malloc(count * size);
	if (!str)
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}

// #include <stdio.h>

// int	main()
// {
// 	int	size = 0;
// 	int	a;
// 	char *p1 = ft_calloc(size, 0);
// 	char *p2 = calloc(size, 0);
// 	a = memcmp(p1, p2, 1);
// 	if (!a)
// 		printf("success\n");
// 	printf("\"%p\"\n", p1);
// 	printf("\"%p\"\n", p2);
// }
