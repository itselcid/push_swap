CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
CNAME = checker
SRC = main.c push_swap.c sort.c push_from_a_to_b.c  helpers.c split.c \
                    moves/rotats.c moves/swaps.c moves/pushes.c moves/reverse_rotats.c
SRC_BNS = split.c helpers.c push_swap.c bonus/checker.c bonus/checker_helpers.c  get_next_line/get_next_line.c \
                    get_next_line/get_next_line_utils.c moves/rotats.c moves/swaps.c moves/pushes.c moves/reverse_rotats.c
OBJ = $(SRC:.c=.o)
OBJ_BNS = $(SRC_BNS:.c=.o)

all: $(NAME)

bonus: $(CNAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(CNAME): $(OBJ_BNS)
	$(CC) $(CFLAGS) $(OBJ_BNS) -o $(CNAME) 

clean:
	@rm -f $(OBJ) $(OBJ_BNS)

fclean: clean
	@rm -f $(NAME) $(CNAME)

re: fclean all
