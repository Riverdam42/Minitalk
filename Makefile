NAME = minitalk
SERVER_NAME = server
CLIENT_NAME = client
LIBFT = ./libft/

SERVER_SRC = ft_server.c
CLIENT_SRC = ft_client.c
UTILS_SRC = minitalk_utils.c

CLIENT_OBJS = $(CLIENT_SRC:.c=.o)
SERVER_OBJS = $(SERVER_SRC:.c=.o)
UTILS_OBJS = $(UTILS_SRC:.c=.o)

INC = includes

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBS = -L./libft -lft

RM = rm -f

all: $(LIBFT) $(NAME)

$(NAME): $(SERVER_NAME) $(CLIENT_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C ./libft

$(SERVER_NAME): $(SERVER_OBJS) $(UTILS_OBJS)
	$(CC) $(CFLAGS) -o $(SERVER_NAME) $(SERVER_OBJS) $(UTILS_OBJS) $(LIBS)

$(CLIENT_NAME): $(CLIENT_OBJS) $(UTILS_OBJS)
	$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(CLIENT_OBJS) $(UTILS_OBJS) $(LIBS)

clean:
	${RM} ${SERVER_OBJS}
	${RM} ${CLIENT_OBJS}
	${RM} ${UTILS_OBJS}

fclean: clean
	${RM} ${SERVER_NAME}
	${RM} ${CLIENT_NAME}

re: fclean all

.PHONY: all clean fclean re
