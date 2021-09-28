/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:00:44 by kkawano           #+#    #+#             */
/*   Updated: 2021/09/28 14:03:09 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		flag = 1;
}

void	send_str(char *str, int pid)
{
	int32_t	bit;
	int		i;

	while (*str)
	{
		bit = (unsigned char)*str++;
		i = -1;
		while (++i < 32)
		{
			if ((bit & 1) == 0)
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(print_error("KILL_ERROR"));
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					exit(print_error("KILL_ERROR"));
			}
			bit = bit >> 1;
			while (flag == 0)
				;
			flag = 0;
		}
	}
}

int	main(int argc, char **argv)
{
	int				pid_server;
	struct sigaction	act;

	act.sa_handler = &signal_handler;
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		exit(print_error("SIGNAL_ERROR"));
	if (argc != 3)
		return (print_error("INVALID_ARGUMENT"));
	pid_server = ft_atoi(argv[1]);
	if (pid_server == 0 || pid_server == -1 || kill(pid_server, 0) == -1)
		return (print_error("EXIT_FAILURE"));
	send_str(argv[2], pid_server);
}