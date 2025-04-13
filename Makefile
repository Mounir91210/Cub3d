SRCS =  main.c utils.c take_map_and_texture.c check_color.c check_texture.c

CC =  cc -Wall -Werror -Wextra -g3
DIRLIB = ./libft
LIBFT = $(DIRLIB)/libft.a
NAME =	cub3d
VMINI = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
		--trace-children=yes --suppressions=minishell.supp \
        --track-fds=yes --quiet

OBJS_DIR = .objets/

SRCS_DIR = srcs/

OBJS = $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

DIR_DUP = mkdir -p $(@D)

all : $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) -o $(NAME) -lreadline
	@echo "cub3d done !"

$(LIBFT) :
	@make -sC $(DIRLIB)


$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@$(DIR_DUP)
	@$(CC) -c $< -o $@ 
	@echo "compiling: $<"

clean :
	@make fclean -sC $(DIRLIB)
	@rm -rf $(OBJS_DIR)
	@echo "refreeeesh baby"

fclean : clean
	@rm -rf $(NAME)

re : fclean all

rlleaks: $(NAME)
	$(VMINI) ./cub3d

.PHONY: all clean fclean re rlleaks
