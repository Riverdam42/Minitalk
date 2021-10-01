/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 00:46:05 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/02 00:46:07 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>

int		main(void)
{
	printf("1 = %d\n", ft_isascii(1));
	printf("1 = %d\n", ft_isascii(127));
	printf("1 = %d\n", ft_isascii(42));
	printf("0 = %d\n", ft_isascii(-3));
	printf("0 = %d\n", ft_isascii(128));
}
*/
