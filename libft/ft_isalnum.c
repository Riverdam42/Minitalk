/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 00:45:40 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/02 00:45:42 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') \
		|| ('0' <= c && c <= '9'))
		return (1);
	else
		return (0);
}

// #include <stdio.h>

// int main(void)
// {
// 	char a = 'k';
// 	char b = 'K';
// 	char c = '1';
// 	char d = '$';
// 	char e = '\0';

// 	printf("1 = %d\n", ft_isalnum(a));
// 	printf("1 = %d\n", ft_isalnum(b));
// 	printf("1 = %d\n", ft_isalnum(c));
// 	printf("0 = %d\n", ft_isalnum(d));
// 	printf("0 = %d\n", ft_isalnum(e));
// 	return 0;
// }
