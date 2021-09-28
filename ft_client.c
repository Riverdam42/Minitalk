/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:00:44 by kkawano           #+#    #+#             */
/*   Updated: 2021/09/27 14:07:36 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t   analyze_pid(char *str)
{
    int n;

    n = 0;
    while (*str)
    {
        if ('0' <= *str && *str <= '9')
            n = n * 10 + *str - '0';
        else
            return (-1);
        str++;
    }
    return (n);
}

static void	send_char(pid_t pid, char c)
{
	int				bit;
	int				i;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = 0;
	while (i < 8)
	{
		usleep(50);
		bit = (uc >> i) & 0x01;
		if (kill(pid, SIGUSR1 + bit) == -1)
			ft_error_exit("kill error");
		i++;
	}
}

