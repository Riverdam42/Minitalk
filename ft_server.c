/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:00:59 by kkawano           #+#    #+#             */
/*   Updated: 2021/09/27 19:55:47 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

static void	handle_signal(int signal)
{
	g_receive_signal = signal;
}

void	set_signal(void)
{
	signal(SIGUSR1, &handle_signal);
}

void	set_signal(void)
{
	struct sigaction	sa;

	sa.sa_handler = &handle_signal;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa_sigusr1.sa_mask, SIGUSR1);
	sigaction(SIGUSR1, &sa, NULL);
}

int	main(void)
{
	pid_t       pid_client;

    pid_client = getpid();
    ft_putnbr_fd(pid_client, 1);
    write(1, "\n", 1);
	//receiver(signal_server_handler); //handlerを確認する
    while (1)
		;
	return (0);
}