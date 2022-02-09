Makefile have some troubles with 'make re'
==> "make: *** No rule to make target `obj', needed by `obj/main.o'.  Stop."



# Done
- remove sprites ; parsing and tests
- Change GNL
- put fanncy textures
## List of errors
- Bad number of arguments OK
- Not a .cub file OK
- Can't find file OK
- Invalid parameters OK
- same paramater define multiples times (works with floor, textures, res) OK
- Invalid map OK
- Texture path without extention OK
- Malloc err OK
- verifier que les paths pointent vers de vrais fichiers .xpm
- if .xpm name but not xpm file
## Cleaning
- remove all exit() (exception in main because no malloc)
- find why some still reachable leaks in init_param() and init_map() ==> GNL when quit before EOF
## Engine
### Player
- player move and rotate
### Raycaster
- raycaster prints images 
- works with textures
- floor and ceilling with values from params


# To check
- conditionnal jump problem with the pivoted map when check holes (check rabbit's paws in l.cub)
- probleme de parsing de map, je devrai mettre des /0 sur toute la longueur de la map quand les tailles sont differentes. **apres moultes reflexions/recherches, il suffit de parcourir chaque ligne jusa'au \0 plutot que de la taille max de la map**
- remove -g from flags (at the end)

# To do
- integrer libft sans submodules
- probleme libft relink
## Errors
- find new errors to check

# Doing
- use two images to avoid blink when many moves
- put raycaster to multiples functions

