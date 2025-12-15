# Libft
# by joao-alm

NAME	= libft.a
LIBCC	= ar rcs
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
O_DIR	= .obj
HEADER	= $(O_DIR)/.header

all: $(NAME)

# Char Files
SRC_CHAR		= src/char/ft_isalnum.c \
				  src/char/ft_isalpha.c \
				  src/char/ft_isascii.c \
				  src/char/ft_isdigit.c \
				  src/char/ft_isprint.c

# Conversion Files
SRC_CONV		= src/conversion/atoll_valid.c \
				  src/conversion/ft_atoi.c \
				  src/conversion/ft_itoa.c \
				  src/conversion/ft_tolower.c \
				  src/conversion/ft_toupper.c

# Error Files
SRC_ERROR		= src/error/error.c

# GetNextLine Files
SRC_GNL			= src/gnl/get_next_line.c \
				  src/gnl/get_next_line_utils.c \
				  src/gnl/gnl_free_buffer.c

# List Files
SRC_LIST		= src/list/ft_lstadd_back_bonus.c \
				  src/list/ft_lstadd_front_bonus.c \
				  src/list/ft_lstclear_bonus.c \
				  src/list/ft_lstdelone_bonus.c \
				  src/list/ft_lstiter_bonus.c \
				  src/list/ft_lstlast_bonus.c \
				  src/list/ft_lstmap_bonus.c \
				  src/list/ft_lstnew_bonus.c \
				  src/list/ft_lstsize_bonus.c \
				  src/list/lstdel_safely.c \
				  src/list/lstdetach.c \
				  src/list/lstdup.c \
				  src/list/lstget_int.c \
				  src/list/lstnew_int.c

# Memory Files
SRC_MEM			= src/memory/free_matrix.c \
				  src/memory/free_partial_matrix.c \
				  src/memory/ft_bzero.c \
				  src/memory/ft_calloc.c \
				  src/memory/ft_memchr.c \
				  src/memory/ft_memcmp.c \
				  src/memory/ft_memcpy.c \
				  src/memory/ft_memmove.c \
				  src/memory/ft_memset.c \
				  src/memory/realloc.c \
				  src/memory/sort_tab.c

# Print Files
SRC_PRINT		= src/print/ft_printf.c \
				  src/print/ft_putchar_fd.c \
				  src/print/ft_putendl_fd.c \
				  src/print/ft_putnbr_fd.c \
				  src/print/ft_putstr_fd.c \
				  src/print/put_characters.c \
				  src/print/put_numbers.c

# String Files
SRC_STRING		= src/string/ft_split.c \
				  src/string/ft_strchr.c \
				  src/string/ft_strcmp.c \
				  src/string/ft_strdup.c \
				  src/string/ft_striteri.c \
				  src/string/ft_strjoin.c \
				  src/string/ft_strlcat.c \
				  src/string/ft_strlcpy.c \
				  src/string/ft_strlen.c \
				  src/string/ft_strmapi.c \
				  src/string/ft_strncmp.c \
				  src/string/ft_strnstr.c \
				  src/string/ft_strrchr.c \
				  src/string/ft_strtrim.c \
				  src/string/ft_substr.c \
				  src/string/intlen.c \
				  src/string/isempty.c \
				  src/string/strarrcount.c \
				  src/string/strarrdup.c \
				  src/string/strcpy.c \
				  src/string/ft_strcat.c \
				  src/string/strjoin_free.c \
				  src/string/strndup.c

# All Sources
SRC				= $(SRC_CHAR) $(SRC_CONV) $(SRC_GNL) $(SRC_LIST) \
				  $(SRC_MEM) $(SRC_PRINT) $(SRC_STRING) $(SRC_ERROR)
OBJ				= $(SRC:%.c=$(O_DIR)/%.o)

$(O_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ -Iinc

$(NAME): $(HEADER) $(OBJ)
	@$(LIBCC) $@ $(OBJ)
	@echo "Libft compiled successfully"

clean:
	@rm -rf $(O_DIR)
	@echo "Libft objects removed successfully"

fclean:
	@rm -rf $(O_DIR)
	@rm -rf $(NAME)
	@echo "Libft objects & executable removed successfully"

re: fclean all

$(HEADER):
	@mkdir -p $(dir $@)
	@touch $@
	@printf "\n"
	@printf "█████████████████████████████\n"
	@printf "        ██  █▓███  ██  █▓███ \n"
	@printf "joao-alm  █████      █████   \n"
	@printf "╦  ┬┌┐ ┌─┐┌┬┐\n"
	@printf "║  │├┴┐├┤  │ \n"
	@printf "╩═╝┴└─┘└   ┴ \n\n"

.PHONY: all clean fclean re
