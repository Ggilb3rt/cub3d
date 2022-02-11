Makefile have some troubles with 'make re'
==> "make: *** No rule to make target `obj', needed by `obj/main.o'.  Stop."



# Done
- remove sprites ; parsing and tests
- Change GNL
- put fanncy textures
- conditionnal jump problem with the pivoted map when check holes
- si fichier enregistre avec vi ou nano ==> devient inutilisable... WTF ?! **==> vi et nano ajoutent un \n a la fin du fichier, message d'erreur normal si on considere que la map doit est strictement la derniere chose du fichier**
## List of errors
- Bad number of arguments
- check open directory
- Not a .cub file
- Can't find file
- Invalid parameters
- same paramater define multiples times (works with floor, textures, res)
- Invalid map
- Texture path without extention
- Malloc err
- verifier que les paths pointent vers de vrais fichiers .xpm
- if .xpm name but not xpm file
- quit when no player
- av[1] is a directory
## Cleaning
- find why some still reachable leaks in init_param() and init_map() ==> GNL when quit before EOF
- no leaks
## Engine
- use two images to avoid blink when many moves
### Player
- player move and rotate
### Raycaster
- raycaster prints images 
- works with textures
- floor and ceilling with values from params
- put raycaster to multiples functions


# To check
- remove -g from flags (at the end)

# To do
- integrer libft sans submodules
- probleme libft relink
## Errors parsing
- find new errors to check

# Doing

