NAME	= libft.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
LIBC	= ar rcs
RM		= rm -f

# --- PARTE OBLIGATORIA ---
SRC	= 

OBJ	= $(SRC:.c=.o)

# --- PARTE BONUS ---
SRC_BONUS	= 

OBJ_BONUS	= $(SRC_BONUS:.c=.o)

# Regla principal (obligatoria)
all: $(NAME)

# Compila la librería uniendo los objetos
# Usamos el condicional para evitar el relink
$(NAME): $(OBJ)
	$(LIBC) $(NAME) $(OBJ)

bonus: .bonus

.bonus: $(OBJ) $(OBJ_BONUS)
	$(LIBC) $(NAME) $(OBJ) $(OBJ_BONUS)
	@touch .bonus
# Compilación de archivos .c en .o
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJ_BONUS) .bonus

fclean: clean
	$(RM) $(NAME)

re: fclean all

# Marcamos las reglas como "falsas" para evitar conflictos con archivos reales
.PHONY: all bonus clean fclean re