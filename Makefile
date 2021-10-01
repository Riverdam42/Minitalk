NAME = minitalk
SERVER_NAME = server
CLIENT_NAME = client
LIBFT = libft.a

SERVER_SRC = ft_server.c
CLIENT_SRC = ft_client.c

BONUS_SRC = ft_server_bonus.c\
			ft_client_bonus.c

CLIENT_OBJS = $(CLIENT_SRC:.c=.o)
SERVER_OBJS = $(SERVER_SRC:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)

INC = includes

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBS = -L./libft -lft

LIBO = ./libft/*.o

LIBA = ./libft/libft.a

RM = rm -f

all: $(LIBFT) $(NAME)

$(NAME): $(SERVER_NAME) $(CLIENT_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C ./libft

$(SERVER_NAME): $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $(SERVER_NAME) $(SERVER_OBJS) $(LIBS)

$(CLIENT_NAME): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(CLIENT_OBJS) $(LIBS)

clean:
	$(RM) $(SERVER_OBJS)
	$(RM) $(CLIENT_OBJS)
	$(RM) $(LIBO)

fclean: clean
	$(RM) $(SERVER_NAME)
	$(RM) $(CLIENT_NAME)
	$(RM) $(LIBA)

re: fclean all

.PHONY: all clean fclean re
