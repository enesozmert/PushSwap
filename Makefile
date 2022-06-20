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

COMMON		= 	main push_swap \
push_swap_main/ft_swap push_swap_main/ft_push push_swap_main/ft_rotate push_swap_main/ft_rev_rotate handler \
arg_to_arr sort_algoritm decimal_to_binary \
list_print hard_solve medium_solve basic_solve \
list_control list_operations list_size

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
			@echo $(NAME) compiled!

clean:
			@$(RM) -rf $(OBJ)
			@echo $(NAME) objects files cleaned!

fclean:		clean
			@$(RM) -f $(NAME)
			@echo $(NAME) executable files cleaned!

re:			fclean all
			@echo Cleaned and rebuilt

.PHONY:		all clean fclean re bonus norm
