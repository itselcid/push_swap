CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRC = push_swap.c \
					moves/rotats.c moves/swaps.c moves/pushes.c 
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
