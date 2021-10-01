/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 00:44:54 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/02 00:44:56 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 32);
	else
		return (c);
}

/*
#include <stdio.h>

int main(void)
{
	char a = 'k';
	char b = 'K';
	char c = '*';

	printf("75 ->%d\n",ft_toupper(a));
	printf("107 ->%d\n",ft_toupper(b));
	printf("74 ->%d\n",ft_toupper(c));
}
*/
