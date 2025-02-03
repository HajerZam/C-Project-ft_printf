NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
INCLUDE_DIR = include

SRC = $(SRC_DIR)/ft_printf.c $(SRC_DIR)/ft_printf_utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(INCLUDE_DIR)/ft_printf.h
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all test clean fclean re