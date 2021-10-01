/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:09:24 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/01 15:52:11 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_info	g_info;

static void	main_iterator(void)
{
	if (g_info.count == 32)
	{
		g_info.buf[g_info.letter++] = g_info.uc;
		g_info.uc = 0;
		g_info.count = 0;
		if (g_info.buf[g_info.letter] == '\0' || g_info.letter == BUFFER_SIZE)
		{
			write(1, g_info.buf, ft_strlen(g_info.buf));
			g_info.letter = 0;
			ft_bzero(g_info.buf, BUFFER_SIZE);
		}
	}
}

static void	signal_action(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	(void)info;
	if (sig == SIGUSR1)
	{
		g_info.count++;
		if (g_info.count != 32)
			g_info.uc <<= 1;
		// if (kill(info->si_pid, SIGUSR1) == ERROR)
		// 	exit(print_error("KILL_ERROR"));
	}
	else if (sig == SIGUSR2)
	{
		g_info.count++;
		g_info.uc += 1;
		if (g_info.count != 32)
			g_info.uc <<= 1;
		// if (kill(info->si_pid, SIGUSR2) == ERROR)
		// 	exit(print_error("KILL_ERROR"));
	}
	main_iterator();
}

static struct sigaction	set_signal(void)
{
	struct sigaction	act;

	ft_bzero(g_info.buf, BUFFER_SIZE);
	act.sa_sigaction = signal_action;
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, NULL) == ERROR
		|| sigaction(SIGUSR2, &act, NULL) == ERROR)
		exit(print_error("SIGACTION_ERROR"));
	return (act);
}

int	main(void)
{
	struct sigaction	act;

	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	g_info.count = 0;
	g_info.uc = 0;
	g_info.letter = 0;
	act = set_signal();
	while (1)
	{
		pause();
	}
	return (0);
}
