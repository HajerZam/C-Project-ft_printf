NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
LIBFT_DIR = libft
INCLUDE_DIR = include

SRC = $(SRC_DIR)/ft_printf.c $(SRC_DIR)/ft_printf_extra.c \
      $(SRC_DIR)/ft_printf_utils.c $(SRC_DIR)/ft_printf_parce.c

OBJ = $(SRC:.c=.o)
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) bonus

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(INCLUDE_DIR)/ft_printf.h $(INCLUDE_DIR)/libft.h
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all