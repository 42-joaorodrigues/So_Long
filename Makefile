# So Long
# by joao-alm

NAME   		= so_long
CC     		= cc
CFLAGS 		= -Wall -Werror -Wextra -Ofast -march=native -Wno-incompatible-pointer-types
LIBS_DIR	= libs
O_DIR		= obj
HEADER		= $(O_DIR)/.header

all: $(NAME)

SRC				= src/game/enemy_bonus.c \
				  src/game/enemy_collision_bonus.c \
				  src/game/enemy_move_horizontal_bonus.c \
				  src/game/enemy_move_vertical_bonus.c \
				  src/game/map_exit_animation_bonus.c \
				  src/game/player.c \
				  src/input/keyhooks.c \
				  src/parser/flood_fill.c \
				  src/parser/parse_elements.c \
				  src/parser/parse_enemy_bonus.c \
				  src/parser/parse_map.c \
				  src/parser/sprite_ids.c \
				  src/parser/void_walls.c \
				  src/render/render.c \
				  src/render/render_counter_bonus.c \
				  src/render/render_enemy_bonus.c \
				  src/render/render_player.c \
				  src/render/sprites.c \
				  src/util/exit.c \
				  src/util/mlx_util.c \
				  src/util/util.c \
				  src/main.c
OBJ 			= $(SRC:%.c=$(O_DIR)/%.o)

$(O_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ -Iinc -Imlx -Ilibft/inc

$(NAME): $(HEADER) $(OBJ)
	@make -C libft --no-print-directory > /dev/null 2>&1
	@echo "Libft compiled successfully"
#	@make -C mlx --no-print-directory > /dev/null 2>&1
#	@echo "Mlx compiled successfully"
	@$(CC) $(CFLAGS) $(OBJ) -o $@ -Llibft -lft -Lmlx -lmlx -lXext -lX11
	@echo "So_Long compiled successfully"

bonus: $(NAME)

clean:
	@rm -rf $(O_DIR)
	@echo "So_Long objects removed successfully"

fclean:
	@rm -rf $(O_DIR)
	@rm -rf $(NAME)
	@echo "So Long objects & executable removed successfully"
	@make -C libft fclean --no-print-directory > /dev/null 2>&1
	@echo "Libft objects & executable removed successfully"
#	@make -C mlx clean --no-print-directory > /dev/null 2>&1
#	@echo "Mlx objects & executable removed successfully"

re: fclean all

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

.PHONY: all bonus clean fclean re
