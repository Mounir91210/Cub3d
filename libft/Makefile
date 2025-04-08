NAME = libft.a

SRC = ft_bzero.c ft_strlen.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
       ft_memcpy.c ft_memset.c ft_strncmp.c ft_tolower.c ft_toupper.c ft_strchr.c \
	   ft_strrchr.c ft_strlcpy.c ft_memcmp.c ft_memchr.c ft_atoi.c ft_strdup.c \
	   ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_strlcat.c ft_split.c \
	   ft_itoa.c ft_strmapi.c ft_striteri.c ft_strnstr.c ft_putchar_fd.c ft_putstr_fd.c \
	   ft_putendl_fd.c ft_putnbr_fd.c ft_memmove.c get_next_line.c ft_putptr.c ft_putstr.c \
	   ft_putnbr.c ft_putnbr_hexa.c ft_putnbr_unsign.c ft_printf.c ft_putchar.c ft_putnbr_base.c \
	   ft_free2d.c ft_print2d.c ft_strcmp.c

OBJ = $(SRC:.c=.o)

# EXEC = a.out

CFLAGS = -Wall -Wextra -Werror -g3

CC = gcc

all : $(NAME)

# $(EXEC) : $(OBJ)
#	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $(SRC)

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)

# ft_strlen.o : ft_strlen.c
#	$(CC) -o ft_strlen.o -c ft_strlen.c

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
