.PHONY: all clean fclean re
NAME	= libft.a
SRCS	= ft_atoi.c \
		  	ft_bzero.c \
		  	ft_calloc.c \
		  	ft_isalnum.c \
		  	ft_isalpha.c \
		  	ft_isascii.c \
		  	ft_isdigit.c \
		  	ft_isprint.c \
		  	ft_itoa.c \
		  	ft_memccpy.c \
		  	ft_memchr.c \
		  	ft_memcmp.c \
		  	ft_memcpy.c \
		 	ft_memmove.c \
		 	ft_memset.c \
		 	ft_putchar_fd.c \
		 	ft_putendl_fd.c \
		 	ft_putnbr_fd.c \
		  	ft_putstr_fd.c \
		  	ft_split.c \
		  	ft_strchr.c \
		  	ft_strdup.c \
		  	ft_strjoin.c \
		  	ft_strlcat.c \
		  	ft_strlcpy.c \
		  	ft_strlen.c \
		  	ft_strmapi.c \
		  	ft_strncmp.c \
		  	ft_strnstr.c \
		  	ft_strrchr.c \
		  	ft_strtrim.c \
		  	ft_substr.c \
		  	ft_tolower.c \
		  	ft_toupper.c \
			get_next_line.c \
			ft_newstr.c \
			ft_check_file_extention.c \
			ft_split_free.c \
			ft_splitted_length.c \
			ft_clear.c
BONUSSRC = ft_lstadd_back.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstlast.c \
			ft_lstsize.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c
OBJS	= $(SRCS:.c=.o)
BONUSOBJ = $(BONUSSRC:.c=.o)
FLAG	= -Wall -Werror -Wextra
CC		= gcc

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)
all:		$(NAME)
bonus:		$(BONUSOBJ) $(OBJS)
			ar rc $(NAME) $(OBJS) $(BONUSOBJ)
			ranlib $(NAME)
%.o: %.c
			@$(CC) $(FLAG) -c -o $@ $<
clean:
			rm -f $(OBJS) $(BONUSOBJ)
fclean:	clean
			rm -f $(NAME)
re:		fclean all
