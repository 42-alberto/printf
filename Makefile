NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Wextra
LIBC	= ar rcs
RM		= rm -rf

# DIRECTORIES
LIBFT_DIR	= libft/
INC_DIR		= includes/
SRC_DIR		= srcs/
UTIL_DIR	= utils/
OBJ_DIR		= obj/

# FILES
SRC_FILES   = ft_printf.c

PRINT_FILES  = ft_put_utils.c\
	ft_count_utils.c\
	ft_print_char.c\
	ft_print_hex.c\
	ft_print_int.c\
	ft_print_str.c\
	ft_print_type.c


OBJS	= $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))\
	$(addprefix $(OBJ_DIR), $(PRINT_FILES:.c=.o))

# INCLUDES
LIBFT	= $(LIBFT_DIR)libft.a
IFLAGS	= -I $(INC_DIR) -I $(LIBFT_DIR)

# VPATH
VPATH	= $(SRC_DIR) $(UTIL_DIR)

# RULES

all: $(NAME)

$(LIBFT):
	@make bonus -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
	@$(LIBC) $(NAME) $(OBJS)
	@echo "✓ $(NAME) created successfully"

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo "  Compiling: $<"

clean:
	@$(RM) $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@echo "✗ Objects removed"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "✗ $(NAME) and libraries removed"

re: fclean all

.PHONY: all clean fclean re