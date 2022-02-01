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
LIBS		= -L ./mlx -lmlx -lXext -lX11 -lm -lbsd -L./lib/libft -lft -lm
RM = /bin/rm -f
MLX		= mlx/libmlx.a

.PHONY: all clean fclean re

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

re: fclean all

fcleanlibft:
	make fclean -C lib/libft/

fcleanall: fclean fcleanlibft

test:
	@printf "\033[0;32m\n\n#TEST EMPTY\n\033[0m"
	./$(NAME) assets/maps/vide.cub
	@printf "\033[0;32m#TEST ANOTHER FILE\n\033[0m"
	./$(NAME) assets/textures/greystone.xpm
	@printf "\033[0;32m\n\n#TEST ERR WRONG PARAM\n\033[0m"
	./$(NAME) assets/maps/err_wrong_param.cub
	@printf "\033[0;32m\n\n#TEST ERR COLOR\n\033[0m"
	./$(NAME) assets/maps/err_color.cub
	@printf "\033[0;32m\n\n#TEST ERR MULTIPLES PARAMS\n\033[0m"
	./$(NAME) assets/maps/err_multi_param.cub
	@printf "\033[0;32m\n\n#TEST ERR MAP\n\033[0m"
	./$(NAME) assets/maps/err_map.cub
	@printf "\033[0;32m\n\n#TEST ERR WRONG CHAR IN MAP\n\033[0m"
	./$(NAME) assets/maps/err_wrong_char_map.cub
	@printf "\033[0;32m\n\nTEST OK big\n\033[0m"
	./$(NAME) assets/maps/l.cub
	@printf "\033[0;32m\n\n#TEST OK little\n\033[0m"
	./$(NAME) assets/maps/little.cub
	

leaks_test: all
	valgrind --leak-check=full ./$(NAME) assets/maps/l.cub