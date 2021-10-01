/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkawano <kkawano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:53:42 by kkawano           #+#    #+#             */
/*   Updated: 2021/10/02 00:52:28 by kkawano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define BUFFER_SIZE 1024
# define ERROR -1

typedef struct s_info
{
	char			buf[BUFFER_SIZE];
	unsigned char	uc;
	int				count;
	int				letter;
}				t_info;

#endif
