/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 00:02:00 by kkawano           #+#    #+#             */
/*   Updated: 2021/09/30 01:38:19 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 1024

char uc;
int count;　//bitの数
int letters;　//bufに収納する文字の数

//シグナルハンドラ(USR1動作を決める)
//シグナルハンドラ(USR1動作を決める)
static void signal_one_handler()
{
	uc <<= 1;
	count++;
}

static void signal_two_handler()
{
	uc += 1;
	uc <<= 1;
	count++;
	if (count == 32)
	buf[letters++] = uc;
}
32回受信するごとにbufに格納する

bufを出力する

int	main(void)
{
	int       pid_client;
	struct sigaction act1;
	struct sigaction act2;

    pid_client = getpid();
    ft_putnbr_fd(pid_client, 1);
    write(1, "\n", 1);
	act.sa_handler = &signal_handler;
	sigaction(SIGUSR1用);
	sigaction(SIGUSR2用);
    while (1)
		;
	return (0);
}