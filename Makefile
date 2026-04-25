NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
LIBC        = ar rcs
RM          = rm -f

# DIRECTORIES
LIBFT_DIR   = libft/
INC_DIR     = includes/
SRC_DIR     = srcs/
UTIL_DIR    = utils/
OBJ_DIR     = obj/

# FILES
SRC_FILES   = ft_printf.c
PRINT_FILES = ft_put_utils.c ft_count_utils.c ft_print_char.c \
              ft_print_hex.c ft_print_int.c ft_print_str.c ft_print_type.c

# OBJS
OBJS        = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o)) \
              $(addprefix $(OBJ_DIR), $(PRINT_FILES:.c=.o))

# INCLUDES
LIBFT       = $(LIBFT_DIR)libft.a
IFLAGS      = -I $(INC_DIR) -I $(LIBFT_DIR)

# VPATH
VPATH       = $(SRC_DIR) $(UTIL_DIR)

# RULES
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
	@$(LIBC) $(NAME) $(OBJS)
	@echo "\033[0;32m✓ $(NAME) created successfully\033[0m"

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo "  Compiling: $<"

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@echo "\033[0;33m✗ Objects removed\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "\033[0;31m✗ $(NAME) removed\033[0m"

re: fclean all

bonus: all

# Test rule
test: all
	@$(CC) $(CFLAGS) -Wno-format tests/main_test.c -I $(INC_DIR) -I $(LIBFT_DIR) \
		-L. -lftprintf -Wl,--wrap=write -o test_printf
	@echo "\033[0;32m✓ Test compiled (Warnings silenced y Wrapper active)\033[0m"
	@valgrind --leak-check=full ./test_printf
	@$(RM) test_printf

.PHONY: all clean fclean re test bonus