CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRC = main.c push_swap.c sort.c push_from_a_to_b.c  helpers.c split.c libft.c \
					moves/rotats.c moves/swaps.c moves/pushes.c moves/reverse_rotats.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
