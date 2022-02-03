#Hello

O = obj/
I = inc/
S = src/
L = lib/

include sources.mk
OBJ = $(SRC:$S%.c=$O%.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
INCFLAGS = -I$I
LDFLAGS = 

RM = /bin/rm -f

.PHONY: all clean fclean re

all : $(NAME)

# Creation of all objects
$O:
	@mkdir -p $@

$(OBJ): | $O

$O%.o: $S%.c | $O
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make bonus -C lib/libft/
	$(CC) $(LDFLAGS) $^ -L./lib/libft -lft -lm -o $@
	#$(CC) $(LDFLAGS) $^ -L./lib/libft -lft -o $@

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
	@printf "\033[0;32m\n#TEST BAD ARG QT\n\033[0m"
	./$(NAME)
	@printf "\033[0;32m\n\n#TEST EMPTY\n\033[0m"
	./$(NAME) assets/maps/vide.cub
	@printf "\033[0;32m\n#TEST ANOTHER FILE\n\033[0m"
	./$(NAME) assets/textures/greystone.xpm
	@printf "\033[0;32m\n\n#TEST ERR WRONG PARAM\n\033[0m"
	./$(NAME) assets/maps/err_wrong_param.cub
	@printf "\033[0;32m\n\n#TEST ERR NOT XPM FILE\n\033[0m"
	./$(NAME) assets/maps/err_not_xpm.cub
	@printf "\033[0;32m\n\n#TEST ERR COLOR\n\033[0m"
	./$(NAME) assets/maps/err_color.cub
	@printf "\033[0;32m\n\n#TEST ERR MULTIPLES PARAMS\n\033[0m"
	./$(NAME) assets/maps/err_multi_param.cub
	@printf "\033[0;32m\n\n#TEST ERR MAP WRONG CHAR\n\033[0m"
	./$(NAME) assets/maps/err_map_char.cub
	@printf "\033[0;32m\n\n#TEST ERR MAP HOLE\n\033[0m"
	./$(NAME) assets/maps/err_map.cub
	@printf "\033[0;32m\n\nTEST OK big\n\033[0m"
	./$(NAME) assets/maps/l.cub
	@printf "\033[0;32m\n\n#TEST OK little\n\033[0m"
	./$(NAME) assets/maps/little.cub
	

leaks_test: all
	valgrind --leak-check=full ./$(NAME) assets/maps/l.cub
	@printf "\033[0;32m\n\n#EARLY QUIT\n\033[0m"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) assets/maps/err_wrong_param.cub