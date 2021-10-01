#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define BUFFER_SIZE 10
# define ERROR -1

int	print_error(char *str);

typedef struct s_info
{
	char buf[BUFFER_SIZE];
	unsigned char	uc;
	int			count; //bitの数を数える
	int			letter; ////bufに収納する文字の数
} t_info;

#endif