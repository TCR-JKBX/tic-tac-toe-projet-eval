CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = tic-tac-toe

all: $(NAME)

$(NAME): main.c tic-tac-toe.h
	$(CC) $(CFLAGS) main.c -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all
