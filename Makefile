NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
LIBC	= ar rcs
RM		= rm -rf

# --- DIRECTORIES ---
LIBFT_DIR	= libft/
INC_DIR		= includes/
SRC_DIR		= srcs/
UTIL_DIR	= utils/
OBJ_DIR		= obj/

# --- FILES ---
SRC_FILES	= ft_printf.c ft_parser.c
UTIL_FILES	= ft_atoi_printf.c ft_flags_activator.c ft_char_in_flags.c

# Generamos los objetos manteniendo la ruta para que las reglas coincidan
OBJS	= $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o)) \
(addprefix $(OBJ_DIR), $(UTIL_FILES:.c=.o))

LIBFT	= $(LIBFT_DIR)libft.a
IFLAGS	= -I $(INC_DIR) -I $(LIBFT_DIR)

# --- RULES ---

all: $(NAME)

$(LIBFT):
	@make bonus -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
	@$(LIBC) $(NAME) $(OBJS)
	@echo "✓ $(NAME) created successfully"

# Regla para fuentes en srcs/
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

# Regla para fuentes en utils/
$(OBJ_DIR)%.o: $(UTIL_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@echo "✗ Objects removed"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "✗ $(NAME) and libft.a removed"

re: fclean all

.PHONY: all clean fclean re