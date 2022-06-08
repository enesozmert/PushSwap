#Definition
CC          =   gcc
LIBFT		=	./includes/libft/libft.a
NAME        =   push_swap
SRC_DIR     =   src
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -f
AR			=	ar rcs

#Files

COMMON		= 	main push_swap ft_swap ft_push ft_rotate ft_rev_rotate handler \
arg_to_arr array_cmp sort_algoritm list_to_arr list_operation decimal_to_binary \
list_print list_size hard_solve medium_solve

#FileCreate

SRC_FILES  	= $(COMMON)

SRC 		= 	$(addsuffix .c, $(SRC_FILES))
OBJ 		= 	$(addsuffix .o, $(SRC_FILES))

all:		$(NAME)

%.o:%.c 
			@echo Compiling:
			@$(CC) $(CFLAGS) -c $< -o $@
			@echo Compiling Success file is : $< $(SRC_FILES) $@ 

norm:
			@norminette $(SRC) | grep -v Norme -B1 || true
			@echo Norminatte exception

build:
			@gcc $(LIBFT) $(SRC) $(CFLAGS) -o $(NAME)
			@echo Build ok

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(OBJ)
			@ranlib $(NAME)
			@echo SoLong compiled!

clean:
			@$(RM) -rf $(OBJ)
			@echo SoLong objects files cleaned!

fclean:		clean
			@$(RM) -f $(NAME)
			@echo SoLong executable files cleaned!

re:			fclean all
			@echo Cleaned and rebuilt

.PHONY:		all clean fclean re bonus norm
