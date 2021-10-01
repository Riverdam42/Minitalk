/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 00:47:24 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/02 00:47:25 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_n(size_t n)
{
	int	len;

	len = 0;
	while (n >= 10)
	{
		len++;
		n /= 10;
	}
	return (len + 1);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	digit;
	long	number;

	number = n;
	digit = 0;
	if (n < 0)
	{
		digit += 1;
		number *= -1;
	}
	digit += count_n(number);
	str = malloc(sizeof(char) * (digit + 1));
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	str[digit] = '\0';
	digit -= 1;
	while ((0 <= n && 0 <= digit) || (0 > n && digit > 0))
	{
		str[digit--] = (number % 10) + '0';
		number /= 10;
	}
	return (str);
}

// #include <limits.h>

// int	main(void)
// {
// 	printf("str = %s\n", ft_itoa(-123456789));
// 	printf("str = %s\n", ft_itoa(123456789));
// 	printf("INT_MAX: str = %s\n", ft_itoa(INT_MAX));
// 	printf("INT_MIN: str = %s\n", ft_itoa(INT_MIN));
// 	return (0);
// }
