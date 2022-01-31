O = obj/
I = inc/
S = src/
L = lib/

#SRC2 = $(patsubst %.c,%.o,$(wildcard ./src/*.c))
#SRC = $(wildcard ./src/*.c)
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
	# $< reference to the first prerequisite

$(NAME): $(OBJ)
	make bonus -C lib/libft/
	$(CC) $(LDFLAGS) $^ -L./lib/libft -lft -o $@
	# $^ reference to all the prerequisites of the rule here is $(OBJ)
	# $@ reference to the name of the rule here is $(NAME)
	#./$(NAME)
	test

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
	./cub3d assets/maps/l.cub