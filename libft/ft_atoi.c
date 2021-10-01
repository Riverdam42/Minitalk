/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 00:45:07 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/02 00:45:09 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_space(const char *str)
{
	if ((*str == ' ') || (*str == '\t') || (*str == '\n')
		|| (*str == '\v') || (*str == '\r') || (*str == '\f'))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long	result;
	int		sign;
	size_t	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] && ft_is_space(&str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] && (('0' <= str[i]) && (str[i] <= '9')))
	{
		if ((result * 10 + (str[i] - '0')) / 10 != result)
		{
			if (sign == -1)
				return (0);
			else
				return (-1);
		}
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return ((int)result * sign);
}

// #include <stdio.h>

// int		main(void)
// {
// 	char str1[] = "+1234ab567";
// 	char str2[] = "123";
// 	char str3[] = "-123";
// 	char str4[] = "  -123";
// 	char str5[] = "987654321";
// 	char str6[] = "12-34";
// 	char str7[] = "+123";
// 	char str8[] = "2147483647";
// 	char str9[] = "-2147483648";

// 	printf("%d\n", ft_atoi(str1));
// 	printf("%d\n", ft_atoi(str2));
// 	printf("%d\n", ft_atoi(str3));
// 	printf("%d\n", ft_atoi(str4));
// 	printf("%d\n", ft_atoi(str5));
// 	printf("%d\n", ft_atoi(str6));
// 	printf("%d\n", ft_atoi(str7));
// 	printf("INT_MAX = %d\n", ft_atoi(str8));
// 	printf("INT_MIN = %d\n", ft_atoi(str9));
// }
