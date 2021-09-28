/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:00:59 by kkawano           #+#    #+#             */
/*   Updated: 2021/09/28 20:50:04 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	end_of_transmission(unsigned char *buf, int index, siginfo_t *info)
{
	ft_putendl_fd((char *)buf, 1);
	ft_bzero(buf, index);
	kill(info->si_pid, SIGUSR2);
	return (0);
}

static void	signal_handler(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned char	buf[33];
	static int				index;
	static int				bit;
	static unsigned char	uc;

	(void)ucontext;
	if (sig == SIGUSR2)
		uc |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (index > 33 - 1)
			print_error("BUF_OVERFLOW");
		if (uc == 0)
			index = end_of_transmission(buf, index, info);
		else
			buf[index++] = uc;
		bit = 0;
		uc = 0;
	}
}

int	main(void)
{
	int       pid_client;
	struct sigaction act;

    pid_client = getpid();
    ft_putnbr_fd(pid_client, 1);
    write(1, "\n", 1);
	act.sa_handler = &signal_handler; //handlerを確認する
    while (1)
		;
	return (0);
}