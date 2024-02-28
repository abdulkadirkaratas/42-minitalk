NAME	= minitalk
SERVER	= server
CLIENT	= client
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): server.c
	$(CC) $(CFLAGS) server.c -o server

$(CLIENT): client.c
	$(CC) $(CFLAGS) client.c -o client

clean:
	$(RM) $(SERVER) $(CLIENT)

fclean: clean

re: fclean all

.PHONY: all $(NAME) clean fclean re
