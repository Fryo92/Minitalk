# Variables

NAME	=	minitalk

CC		=	cc
FLAG	=	-Wall -Wextra -Werror

DIRLIB	=	./libft/
FILELIB	=	libft.a
NAMELFT	=	$(addprefix $(DIRLIB), $(FILELIB))

SRC_DIR	=	src/
OBJ_DIR =	obj/
INCLUDE	=	-I./include -I./libft/include


# Colors

DEF_COLOR	= \033[0;39m
GRAY 		= \033[0;90m
RED 		= \033[0;91m
GREEN 		= \033[0;92m
YELLOW 		= \033[0;93m
BLUE		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m

# Sources

FILES	=	client server

SRCS	=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS	=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

###

OBJF	=	.cache_exists

$(OBJF)	:
	@mkdir -p $(OBJ_DIR)

all		:	$(NAME)

libft/libft.a:
	@echo "$(YELLOW)COMPILING $(DIRLIB)$(DEF_COLOR)"
	@make -C $(DIRLIB)

$(NAME)	:	libft/libft.a $(OBJS)
	@echo "$(YELLOW)COMPILING MINITALK...$(DEF_COLOR)"
	$(CC) $(FLAG) ./src/server.c $(NAMELFT) $(INCLUDE) -o server
	$(CC) $(FLAG) ./src/client.c $(NAMELFT) $(INCLUDE) -o client
	@echo "$(GREEN)Minitalk compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c | $(OBJF)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean	:
	@make clean -sC $(DIRLIB)
	@rm -rf $(OBJ_DIR)
	@$(RM) -f $(OBJF)
	@echo "$(MAGENTA)Minitalk objects cleaned!$(DEF_COLOR)"

fclean	:	clean
	@rm -f client server
	@rm -f $(NAMELFT)
	@echo "$(YELLOW)Libft cleaned!$(DEF_COLOR)"
	@echo "$(YELLOW)Minitalk executable cleaned!$(DEF_COLOR)"

re		:	fclean all
	@echo "$(GREEN)Cleaned and rebuilt!$(DEF_COLOR)"

.PHONY	:	all clean fclean re