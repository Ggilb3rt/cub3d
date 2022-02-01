Makefile have some troubles with 'make re'
==> "make: *** No rule to make target `obj', needed by `obj/main.o'.  Stop."


#List of errors
- Bad number of arguments OK
- Not a .cub file OK
- Can't find file OK
- Invalid parameters OK
- same paramater define multiples times (works with floor, textures, res) OK
- Invalid map OK
- Texture path without extention OK

- System can't allocate memory, try again


#To check
- conditionnal jump problem with the pivoted map when check holes (check rabbit's paws in l.cub)
- remove -g from flags (at the end)

#To do
- remove sprites parsing and tests
- verifier que les paths pointent vers de vrais fichiers

#Doing
- clean quit (free all params and map). Il faut que je remplace les exit() du parser. Ou que j'ajoute les free directement dans les fonction avant de quit.

ft_exit(*t_params, *t_map)

- probleme de parsing de map, je devrai mettre des /0 sur toute la longueur de la map quand les tailles sont differentes