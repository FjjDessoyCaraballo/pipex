SRCS = format_check.c\
ft_hex.c\
ft_char.c\
ft_pointer.c\
ft_printf.c\
ft_nbr.c\
ft_str.c\
ft_unsig_nbr.c

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

OFILES = $(SRCS:.c=.o)

NAME = libftprintf.a

LIBFT = libft/libft.a

LIBFT_DIR = libft

all: $(NAME)

$(NAME): $(OFILES) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OFILES)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OFILES)
	make clean -C $(LIBFT_DIR)
 
fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re