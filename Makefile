###############################################################################
#                               So Long by joao-alm                           #
#                                                                             #
###############################################################################

#──────────────────────────────Compilation Settings───────────────────────────#

NAME   		= so_long
CC     		= cc
CFLAGS 		= -Wall -Werror -Wextra -Wno-incompatible-pointer-types
LIBS_DIR	= libs
O_DIR		= obj

all: $(HEADER) $(LIBFT) $(NAME)

#───────────────────────────────Animation Variables───────────────────────────#

YELLOW			= \033[38;2;255;248;147m# FFF893
PINK			= \033[38;2;231;133;190m# E785BE
GREEN			= \033[38;2;129;223;164m# 81DFA4
RESET			= \033[0m

HEADER			= $(O_DIR)/.header
COMPILED_COUNT	= $(O_DIR)/.compiled_count

#──────────────────────────────────MiniLibX───────────────────────────────────#

MLX_DIR	= $(LIBS_DIR)/mlx
MLX		= $(MLX_DIR)/libmlx.a
MLX_INC		= -I $(MLX_DIR)
MLX_ADD		= -L $(MLX_DIR) -lmlx -lXext -lX11

$(MLX_DIR):
	@mkdir -p $(dir $@)
	@git clone https://github.com/42-joaorodrigues/compiled_mlx.git $@ > /dev/null 2>&1 || true
	@make .progress ACTION="Downloading" OBJECT="mlx" --no-print-directory 

$(MLX): $(MLX_DIR)

rm_MLX:
	@rm -rf $(MLX_DIR)

#──────────────────────────────────Libft──────────────────────────────────────#

LIBFT_DIR	= $(LIBS_DIR)/libft
LIBFT		= $(LIBFT_DIR)/libft.a
LFT_INC		= -I $(LIBFT_DIR)/inc
LFT_ADD		= -L $(LIBFT_DIR) -l ft

$(LIBFT_DIR):
	@mkdir -p $(dir $@)
	@git clone https://github.com/42-joaorodrigues/mylib.git $@ > /dev/null 2>&1 || true
	@make .progress ACTION="Downloading" OBJECT="libft" --no-print-directory 

$(LIBFT): $(LIBFT_DIR)
	@make -C $(LIBFT_DIR) --no-print-directory

rm_libft:
	@rm -rf $(LIBFT_DIR)

#────────────────────────────Mandatory Compilation────────────────────────────#

SRC				= src/parser/flood_fill.c \
				  src/parser/map_data.c \
				  src/parser/parse_map.c \
				  src/parser/sprite_ids.c \
				  src/parser/void_walls.c \
				  src/exit_animation.c \
				  src/exit.c \
				  src/keyhooks.c \
				  src/main.c \
				  src/mlx_util.c \
				  src/player.c \
				  src/render.c \
				  src/sprites.c \
				  src/util.c
OBJ 			= $(SRC:%.c=$(O_DIR)/mandatory/%.o)
INC				= -I inc $(MLX_INC) $(LFT_INC)

OBJ_COUNT 		= $(words $(OBJ))

# Compile .c to .o
$(O_DIR)/mandatory/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC);
	@current=$$(cat $(COMPILED_COUNT) 2>/dev/null || echo 0); \
	percent=$$(( ($$current * 100) / $(OBJ_COUNT) )); \
	filled=$$(( $$percent / 10 )); \
	printf "%-12.12s %-10.10s " "Compiling" "push_swap"; \
	for j in $$(seq 1 $$filled); do printf "⣿"; done; \
	for j in $$(seq $$filled 9); do printf "⣀"; done; \
	printf " $$percent%%\r"; \
	next=$$(( $$current + 1 )); \
	echo $$next > $(COMPILED_COUNT)

# Compile Push_Swap
$(NAME): $(HEADER) $(MLX) $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@ $(MLX_ADD) $(LFT_ADD)
	@make .success ACTION="Compiling" OBJECT="$(NAME)" --no-print-directory
	@rm -f $(COMPILED_COUNT)

#────────────────────────────────Bonus Compilation────────────────────────────#

B_SRC			= 
B_OBJ			= $(B_SRC:%.c=$(O_DIR)/bonus/%.o)
B_INC			= -I inc $(LFT_INC)

BONUS_OBJ_COUNT = $(words $(B_OBJ))

# Compile .c to .o
$(O_DIR)/bonus/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(B_INC);
	@current=$$(cat $(COMPILED_COUNT) 2>/dev/null || echo 0); \
	percent=$$(( ($$current * 100) / $(BONUS_OBJ_COUNT) )); \
	filled=$$(( $$percent / 10 )); \
	printf "%-12.12s %-10.10s " "Compiling" "checker"; \
	for j in $$(seq 1 $$filled); do printf "⣿"; done; \
	for j in $$(seq $$filled 9); do printf "⣀"; done; \
	printf " $$percent%%\r"; \
	next=$$(( $$current + 1 )); \
	echo $$next > $(COMPILED_COUNT)

# Compile Bonus
bonus: $(HEADER) $(LIBFT) $(B_OBJ)
	@$(CC) $(CFLAGS) $(B_OBJ) -o $@ $(LFT_ADD)
	@make .success ACTION="Compiling" OBJECT="$(CHECKER)" --no-print-directory
	@rm -f $(COMPILED_COUNT)

#────────────────────────────────Cleaning Commands────────────────────────────#

clean:
	@rm -rf $(O_DIR)
	@make .progress ACTION="Cleaning" OBJECT="$(NAME)" --no-print-directory

fclean:
	@rm -rf $(O_DIR)
	@rm -rf $(NAME)
	@make .progress ACTION="Cleaning" OBJECT="$(NAME)" --no-print-directory

re: fclean all

#─────────────────────────────────Animation Rules────────────────────────────#

$(HEADER):
	@mkdir -p $(dir $@)
	@touch $@
	@printf "\n"
	@printf "█████████████████████████████\n"
	@printf "        ██  █▓███  ██  █▓███ \n"
	@printf "joao-alm  █████      █████   \n"
	@printf "╔═╗┌─┐  ╦  ┌─┐┌┐┌┌─┐\n"
	@printf "╚═╗│ │  ║  │ │││││ ┬\n"
	@printf "╚═╝└─┘  ╩═╝└─┘┘└┘└─┘\n\n"

BAR_SIZE ?= 10

.progress:
	@bar_size=$(BAR_SIZE); \
	increment=$$(( 100 / $$bar_size )); \
	filled=0; \
	for i in $$(seq 1 $$(( $$bar_size - 1 ))); do \
		percent=$$(( $$i * $$increment )); \
		printf "%-12.12s %-10.10s " $(ACTION) $(OBJECT); \
		for j in $$(seq 1 $$filled); do printf "⣿"; done; \
		for j in $$(seq $$filled $$bar_size); do printf "⣀"; done; \
		printf " $$percent%%\r"; \
		sleep 0.05; \
		filled=$$i; \
	done; \
	make .success ACTION=$(ACTION) OBJECT=$(OBJECT) --no-print-directory

.success:
	@printf "%-12.12s %-10.10s " $(ACTION) $(OBJECT); \
	bar_size=$(BAR_SIZE); \
	for j in $$(seq 1 $$bar_size); do printf "⣿"; done; \
	printf " 100%%\n"

#────────────────────────────────Phony Targets───────────────────────────────#

.PHONY: all bonus clean fclean re
