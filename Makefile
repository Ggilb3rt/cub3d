#Hello

O = obj/
I = inc/
S = src/
L = lib/

include sources.mk
OBJ = $(SRC:$S%.c=$O%.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
INCFLAGS = -I$I
LDFLAGS = 
LIBS = -L ./mlx -lmlx -lXext -lX11 -lm -lbsd -L./lib/libft -lft
RM = /bin/rm -f
MLX	= mlx/libmlx.a

.PHONY: all clean fclean re test leaks_test_err leaks_test_map

all : $(NAME)

# Creation of all objects
$O:
	@mkdir -p $@

$(OBJ): | $O

$O%.o: $S%.c | $O
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

$(NAME): $(MLX) $(OBJ)
	make bonus -C lib/libft/
	$(CC) $(LDFLAGS) $^ $(LIBS) -o $@

$(MLX):
				@$(MAKE) -C mlx
				@echo "mlx compiled"

cleanobj:
	$(RM) $(wildcard $(OBJ))
	$(RM) -r $(O)

clean: cleanobj
fclean: clean
	$(RM) $(NAME)

re: fcleanall all


fcleanlibft:
	make fclean -C lib/libft/

fcleanall: fclean fcleanlibft

test: all
	@printf "\033[0;32m\n#TEST BAD ARG QT\n\033[0m"
	./$(NAME)
	@printf "\033[0;32m\n\n#TEST DIRECTORY\n\033[0m"
	./$(NAME) assets/maps/err_dir.cub
	@printf "\033[0;32m\n\n#TEST EMPTY\n\033[0m"
	./$(NAME) assets/maps/vide.cub
	@printf "\033[0;32m\n#TEST ANOTHER FILE\n\033[0m"
	./$(NAME) assets/textures/greystone.xpm
	@printf "\033[0;32m\n\n#TEST ERR WRONG PARAM\n\033[0m"
	./$(NAME) assets/maps/err_wrong_param.cub
	@printf "\033[0;32m\n\n#TEST ERR NOT XPM FILE\n\033[0m"
	./$(NAME) assets/maps/err_not_xpm.cub
	@printf "\033[0;32m\n\n#TEST ERR TYPE\n\033[0m"
	./$(NAME) assets/maps/err_type.cub
	@printf "\033[0;32m\n\n#TEST ERR COLOR VALUE\n\033[0m"
	./$(NAME) assets/maps/err_color_val.cub
	@printf "\033[0;32m\n\n#TEST ERR MULTIPLES PARAMS\n\033[0m"
	./$(NAME) assets/maps/err_multi_param.cub
	@printf "\033[0;32m\n\n#TEST ERR MAP WRONG CHAR\n\033[0m"
	./$(NAME) assets/maps/err_map_char.cub
	@printf "\033[0;32m\n\n#TEST ERR MAP MULTI PLAYERS\n\033[0m"
	./$(NAME) assets/maps/err_map_multi_players.cub
	@printf "\033[0;32m\n\n#TEST ERR MAP HOLE\n\033[0m"
	./$(NAME) assets/maps/err_map_hole_horizon.cub
	@printf "\033[0;32m\n\n#TEST ERR MAP HOLE\n\033[0m"
	./$(NAME) assets/maps/err_map_hole_vertical.cub
	@printf "\033[0;32m\n\n#TEST ERR MAP NO PLAYER\n\033[0m"
	./$(NAME) assets/maps/err_map_no_player.cub
	@printf "\033[0;32m\n\n#TEST ERR FAKE XPM FILE\n\033[0m"
	./$(NAME) assets/maps/err_fake_xpm.cub
	@printf "\033[0;32m\n\nTEST OK big\n\033[0m"
	./$(NAME) assets/maps/large.cub

leaks_test_map: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) assets/maps/alone_in_space.cub

leaks_test_err:
	@printf "\033[0;32m\n\n#EARLY QUIT\n\033[0m"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) assets/maps/err_color_val.cub
	@printf "\033[0;32m\n\n#EARLY QUIT\n\033[0m"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) assets/maps/err_map_char.cub
	@printf "\033[0;32m\n\n#EARLY QUIT\n\033[0m"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) assets/maps/err_map_multi_players.cub
	@printf "\033[0;32m\n\n#EARLY QUIT\n\033[0m"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) assets/maps/err_map_hole_horizon.cub
	@printf "\033[0;32m\n\n#EARLY QUIT\n\033[0m"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) assets/maps/err_map_hole_vertical.cub
	@printf "\033[0;32m\n\n#EARLY QUIT\n\033[0m"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) assets/maps/err_multi_param.cub
	@printf "\033[0;32m\n\n#EARLY QUIT\n\033[0m"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) assets/maps/err_not_xpm.cub
	@printf "\033[0;32m\n\n#EARLY QUIT\n\033[0m"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) assets/maps/err_path.cub
	@printf "\033[0;32m\n\n#EARLY QUIT\n\033[0m"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) assets/maps/err_qt.cub
	@printf "\033[0;32m\n\n#EARLY QUIT\n\033[0m"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) assets/maps/err_type.cub
	@printf "\033[0;32m\n\n#EARLY QUIT\n\033[0m"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) assets/maps/err_wrong_param.cub
	@printf "\033[0;32m\n\n#EARLY QUIT\n\033[0m"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) assets/maps/vide.cub
	@printf "\033[0;32m\n\n#EARLY QUIT\n\033[0m"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) assets/maps/err_fake_xpm.cub
	@printf "\033[0;32m\n\n#EARLY QUIT\n\033[0m"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) assets/maps/err_map_no_player.cub
	@printf "\033[0;32m\n\n#EARLY QUIT\n\033[0m"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) assets/maps/err_dir.cub