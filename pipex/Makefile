# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -g
INCFLAGS = -Iincludes

# Main project files
SRC_FILES = parsing.c pipex.c main.c
OBJ_FILES = $(SRC_FILES:.c=.o)
EXECUTABLE = pipex

# Directories
LIBFT_DIR = libft
LIBFT_MAKEFILE = $(LIBFT_DIR)/Makefile
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)/includes
LIBFT_LINK = -L$(LIBFT_DIR) -lft

# Dependencies
DEP = $(OBJ_FILES:.o=.d)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT_LINK) -o $(EXECUTABLE)

%.o: %.c
	$(CC) $(CFLAGS) $(INCFLAGS) $(LIBFT_INC) -c $< -o $@

-include $(DEP)

$(LIBFT): $(LIBFT_MAKEFILE)
	$(MAKE) -C $(LIBFT_DIR)

$(LIBFT_MAKEFILE):
	@echo "Creating symbolic link for libft Makefile..."
	ln -s $(CURDIR)/$(LIBFT_MAKEFILE) $(LIBFT_MAKEFILE)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ_FILES) $(DEP)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(EXECUTABLE)

re: fclean all

.PHONY: all clean fclean re
