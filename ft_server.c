/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 00:02:00 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/01 00:15:08 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_info g_info;

static void signal_one_handler(int sig, siginfo_t *info, void *ucontext) //bit = 0
{
	(void)ucontext;
	(void)sig;
	g_info.uc <<= 1;
	g_info.count++;
	if (kill(info->si_pid, SIGUSR1) == -1)
		exit(print_error("KILL_ERROR"));
	write(1, &(g_info.count), 1);
}

static void signal_two_handler(int sig, siginfo_t *info, void *ucontext) //bit = 1
{
	(void)ucontext;
	(void)sig;
	g_info.uc += 1;
	g_info.uc <<= 1;
	g_info.count++;
	if (kill(info->si_pid, SIGUSR2) == -1)
		exit(print_error("KILL_ERROR"));
}

static void main_iterator(void)
{
	while (1)
	{
		pause();
		if (g_info.count == 32)
		{
			g_info.buf[g_info.letter++] = g_info.uc;
			write(1, g_info.buf, 1); //32カウントしたらbuf(に格納されたuc)を出力
			g_info.uc = 0;
			g_info.count = 0;
		}
	}
}

static void set_signal(void)
{
	struct sigaction act1;
	struct sigaction act2;

	act1.sa_sigaction = &signal_one_handler;
	act2.sa_sigaction = &signal_two_handler;
	act1.sa_flags = SA_SIGINFO;
	act2.sa_flags = SA_SIGINFO;
	sigemptyset(&act1.sa_mask);
	sigemptyset(&act2.sa_mask);
	if (sigaction(SIGUSR1, &act1, NULL) == -1
			|| sigaction(SIGUSR2, &act2, NULL) == -1)
		exit(print_error("SIGACTION_ERROR"));
}

int	main(void)
{
	set_signal();
    ft_putnbr_fd(getpid(), 1);
    write(1, "\n", 1);
	main_iterator();
	return (0);
}