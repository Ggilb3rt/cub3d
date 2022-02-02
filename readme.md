Makefile have some troubles with 'make re'
==> "make: *** No rule to make target `obj', needed by `obj/main.o'.  Stop."



#Done
##List of errors
- Bad number of arguments OK
- Not a .cub file OK
- Can't find file OK
- Invalid parameters OK
- same paramater define multiples times (works with floor, textures, res) OK
- Invalid map OK
- Texture path without extention OK



#To check
- conditionnal jump problem with the pivoted map when check holes (check rabbit's paws in l.cub)
- probleme de parsing de map, je devrai mettre des /0 sur toute la longueur de la map quand les tailles sont differentes. **apres moultes reflexions/recherches, il suffit de parcourir chaque ligne jusa'au \0 plutot que de la taille max de la map**
- remove -g from flags (at the end)

#To do
- remove sprites parsing and tests
- verifier que les paths pointent vers de vrais fichiers
##List of errors
- System can't allocate memory, try again

#Doing
- clean quit (free all params and map). Il faut que je remplace les exit() du parser. Ou que j'ajoute les free directement dans les fonction avant de quit.

ft_exit(*t_params, *t_map)
