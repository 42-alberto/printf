NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
LIBC	= ar rcs
RM		= rm -f

# Lista de archivos creados
SRC	= ft_printf.c \
ft_printf_utils.c\


OBJ	= $(SRC:.c=.o)

# Cabecera de proyecto para tener código reutilizable
HEADER  = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
	$(LIBC) $(NAME) $(OBJ)

# Compilación de archivos .c en .o
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# Marcamos las reglas como "falsas" para evitar conflictos con archivos reales
.PHONY: all clean fclean re