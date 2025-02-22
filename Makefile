NAME= push_swap

CC= cc

CFLAGS= -Wall -Werror -Wextra -g

SRC= main.c operations_a.c operations_b.c radix_sort.c validate.c sort.c

LIB= libft/libft.a

OBJ= $(SRC:.c=.o)

GREEN=\033[0;32m
RED=\033[0;31m
RESET=\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@ make -C libft
	@ $(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB)
	@ echo "                                   "
	@ echo "$(GREEN)✅ Build completed!$(RESET)"
	@ echo "                                   "

%.o: %.c
	@ $(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@ echo "                                      "
	@ echo "$(RED)🗑️  successfully deleted$(RESET)"
	@ echo "                                      "
	@ make clean -C libft

fclean: clean
	@ rm -f $(NAME)
	@ make fclean -C libft

re: fclean all
