NAME = minitalk
SERVER_NAME = server
CLIENT_NAME = client

SERVER_SRC = ft_server.c
CLIENT_SRC = ft_client.c

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

INC = includes

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME): $(SERVER_NAME) $(CLIENT_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER_NAME): $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $(SERVER_NAME) $(SERVER_OBJS)

$(CLIENT_NAME): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(CLIENT_OBJS)

clean:
	${RM} ${SERVER_OBJS}
	${RM} ${CLIENT_OBJS}

fclean: clean
	${RM} ${SERVER_NAME}
	${RM} ${CLIENT_NAME}

re: fclean all

.PHONY: all clean fclean re