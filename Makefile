NAME		= minitalk
CLIENT_NAME	= client
SERVER_NAME	= server
LIBFT_NAME = libft/libft.a

CLIENT_SRCS		= ft_client.c
SERVER_SRCS		= ft_server.c
CLIENT_OBJS		= $(CLIENT_SRCS:%.c=%.o)
SERVER_OBJS		= $(SERVER_SRCS:%.c=%.o)

BONUS_CLIENT_SRCS	= ft_client_bonus.c
BONUS_SERVER_SRCS	= ft_server_bonus.c
BONUS_CLIENT_OBJS	= $(BONUS_CLIENT_SRCS:%.c=%.o)
BONUS_SERVER_OBJS	= $(BONUS_SERVER_SRCS:%.c=%.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM = rm -f

LIBFT_PATH	= ./libft

all : $(NAME)

$(NAME) : $(LIBFT_NAME) $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME) : $(CLIENT_OBJS) $(LIBFT_NAME)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -L$(LIBFT_PATH) -lft -o $(CLIENT_NAME)

$(SERVER_NAME) :$(SERVER_OBJS) $(LIBFT_NAME)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -L$(LIBFT_PATH) -lft -o $(SERVER_NAME)

$(LIBFT_NAME) : force_look
		make -C $(LIBFT_PATH)

force_look :
	@true

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

bonus : $(BONUS_CLIENT_OBJS) $(BONUS_SERVER_OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(BONUS_CLIENT_OBJS) -L$(LIBFT_PATH) -lft -o $(CLIENT_NAME)
	$(CC) $(CFLAGS) $(BONUS_SERVER_OBJS) -L$(LIBFT_PATH) -lft -o $(SERVER_NAME)


clean :
	make clean -C $(LIBFT_PATH)
	$(RM) $(CLIENT_OBJS)
	$(RM) $(SERVER_OBJS)
	$(RM) $(BONUS_CLIENT_OBJS)
	$(RM) $(BONUS_SERVER_OBJS)

fclean : clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(CLIENT_NAME)
	$(RM) $(SERVER_NAME)

re : fclean all

.PHONY : all clean fclean re bonus $(NAME) force_look
