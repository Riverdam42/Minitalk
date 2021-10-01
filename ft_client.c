/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:00:44 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/01 15:47:27 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_str(char *str, int pid_server)
{
	int32_t		bit;
	int			i;
	int			c;

	while (*str)
	{
		bit = (unsigned char)*str++;
		i = -1;
		c = 32;
		while (++i < 32)
		{
			if ((bit & (1 << --c)) == 0)
			{
				if (kill(pid_server, SIGUSR1) == ERROR)
					exit(print_error("KILL_ERROR"));
			}
			else
			{
				if (kill(pid_server, SIGUSR2) == ERROR)
					exit(print_error("KILL_ERROR"));
			}
			usleep(100);
		}
	}
}

int	main(int argc, char **argv)
{
	int					pid_server;

	if (argc != 3)
		return (print_error("INVALID_ARGUMENT"));
	pid_server = ft_atoi(argv[1]);
	if (pid_server == 0 || pid_server == -1
		|| pid_server == 1 || kill(pid_server, 0) == ERROR)
		return (print_error("EXIT_FAILURE"));
	send_str(argv[2], pid_server);
}
