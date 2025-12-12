################################################################################
#                              libft by joao-alm                               #
#                                 Version 1.1                                  #
################################################################################

#────────────────────────────────────Compilation──────────────────────────────#

NAME			= libft.a
LIBC			= ar rcs
CC				= cc
CFLAGS			= -Wall -Werror -Wextra
RM				= rm -rf
O_DIR			= obj

all: $(NAME)

#──────────────────────────────────────Sources────────────────────────────────#

# Char Files
SRC_CHAR		= ft_isalnum.c \
				  ft_isalpha.c \
				  ft_isascii.c \
				  ft_isdigit.c \
				  ft_isprint.c
SRC_CHAR		:= $(addprefix char/, $(SRC_CHAR))

# Conversion Files
SRC_CONV		= atoll_valid.c \
				  ft_atoi.c \
				  ft_itoa.c \
				  ft_tolower.c \
				  ft_toupper.c
SRC_CONV		:= $(addprefix conversion/, $(SRC_CONV))

# Error Files
SRC_ERROR		= error.c
SRC_ERROR		:= $(addprefix error/, $(SRC_ERROR))

# GetNextLine Files
SRC_GNL			= get_next_line.c \
				  get_next_line_utils.c \
				  gnl_free_buffer.c
SRC_GNL			:= $(addprefix gnl/, $(SRC_GNL))

# List Files
SRC_LIST		= ft_lstadd_back_bonus.c \
				  ft_lstadd_front_bonus.c \
				  ft_lstclear_bonus.c \
				  ft_lstdelone_bonus.c \
				  ft_lstiter_bonus.c \
				  ft_lstlast_bonus.c \
				  ft_lstmap_bonus.c \
				  ft_lstnew_bonus.c \
				  ft_lstsize_bonus.c \
				  lstdel_safely.c \
				  lstdetach.c \
				  lstdup.c \
				  lstget_int.c \
				  lstnew_int.c
SRC_LIST		:= $(addprefix list/, $(SRC_LIST))

# Memory Files
SRC_MEM			= free_matrix.c \
				  free_partial_matrix.c \
				  ft_bzero.c \
				  ft_calloc.c \
				  ft_memchr.c \
				  ft_memcmp.c \
				  ft_memcpy.c \
				  ft_memmove.c \
				  ft_memset.c \
				  realloc.c \
				  sort_tab.c
SRC_MEM			:= $(addprefix memory/, $(SRC_MEM))

# Print Files
SRC_PRINT		= ft_printf.c \
				  ft_putchar_fd.c \
				  ft_putendl_fd.c \
				  ft_putnbr_fd.c \
				  ft_putstr_fd.c \
				  put_characters.c \
				  put_numbers.c
SRC_PRINT		:= $(addprefix print/, $(SRC_PRINT))

# String Files
SRC_STRING		= ft_split.c \
				  ft_strchr.c \
				  ft_strcmp.c \
				  ft_strdup.c \
				  ft_striteri.c \
				  ft_strjoin.c \
				  ft_strlcat.c \
				  ft_strlcpy.c \
				  ft_strlen.c \
				  ft_strmapi.c \
				  ft_strncmp.c \
				  ft_strnstr.c \
				  ft_strrchr.c \
				  ft_strtrim.c \
				  ft_substr.c \
				  intlen.c \
				  isempty.c \
				  strarrcount.c \
				  strarrdup.c \
				  strcpy.c \
				  ft_strcat.c \
				  strjoin_free.c \
				  strndup.c
SRC_STRING		:= $(addprefix string/, $(SRC_STRING))

# All Sources
SRC				= $(SRC_CHAR) $(SRC_CONV) $(SRC_GNL) $(SRC_LIST) \
				  $(SRC_MEM) $(SRC_PRINT) $(SRC_STRING) $(SRC_ERROR)
SRC				:= $(addprefix src/, $(SRC))
INC				= -I inc
OBJ				= $(SRC:%.c=$(O_DIR)/%.o)

#───────────────────────────────Animation Variables───────────────────────────#

YELLOW	= \033[38;2;255;248;147m# FFF893
PINK	= \033[38;2;231;133;190m# E785BE
GREEN	= \033[38;2;129;223;164m# 81DFA4
RESET	= \033[0m

COMPILED_COUNT_FILE = $(O_DIR)/.compiled_count

#───────────────────────────────Compilation Commands──────────────────────────#

TOTAL_OBJ = $(words $(OBJ))

$(O_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@current=$$(cat $(COMPILED_COUNT_FILE) 2>/dev/null || echo 0); \
	percent=$$(( ($$current * 100) / $(TOTAL_OBJ) )); \
	filled=$$(( $$percent / 10 )); \
	printf "%-12.12s %-10.10s " "Compiling" "libft"; \
	for j in $$(seq 1 $$filled); do printf "⣿"; done; \
	for j in $$(seq $$filled 9); do printf "⣀"; done; \
	printf " $$percent%%\r"; \
	$(CC) $(CFLAGS) -c $< -o $@ $(INC); \
	next=$$(( $$current + 1 )); \
	echo $$next > $(COMPILED_COUNT_FILE)

$(NAME): $(OBJ)
	@$(LIBC) $@ $(OBJ)
	@printf "%-12.12s %-10.10s $(GREEN)⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ 100%%$(RESET)\n" "Compiling" "libft"
	@rm -rf $(COMPILED_COUNT_FILE)

#─────────────────────────────────Cleaning Commands───────────────────────────#

clean:
	@printf "%-12.12s %-10.10s ⣿⣀⣀⣀⣀⣀⣀⣀⣀⣀ 10%%\r" "Cleaning" "libft"
	@rm -rf $(O_DIR)
	@printf "%-12.12s %-10.10s $(GREEN)⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ 100%%\n$(RESET)" "Cleaning" "libft"

fclean:
	@printf "%-12.12s %-10.10s ⣿⣀⣀⣀⣀⣀⣀⣀⣀⣀ 10%%\r" "Cleaning" "libft"
	@rm -rf $(O_DIR)
	@rm -rf $(NAME)
	@printf "%-12.12s %-10.10s $(GREEN)⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ 100%%\n$(RESET)" "Cleaning" "libft"

re: fclean all

#────────────────────────────────Phony Targets───────────────────────────────#

.PHONY: all clean fclean re
