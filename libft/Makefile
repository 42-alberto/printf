NAME        = libft.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I .
RM          = rm -rf

# --- DIRECTORIES ---
SRC_DIR     = srcs/
OBJ_DIR     = obj/
SUBDIRS     = is lst mem put str to

# --- SOURCE FILES ---
IS_SRCS     = ft_isalnum.c \
ft_isalpha.c \
              ft_isascii.c \
              ft_isdigit.c \
              ft_isprint.c

MEM_SRCS    = ft_bzero.c \
              ft_calloc.c \
              ft_memchr.c \
              ft_memcmp.c \
              ft_memcpy.c \
              ft_memmove.c \
              ft_memset.c

PUT_SRCS    = ft_putchar_fd.c \
              ft_putendl_fd.c \
              ft_putnbr_fd.c \
              ft_putstr_fd.c

STR_SRCS    = ft_split.c \
              ft_strchr.c \
              ft_strdup.c \
              ft_striteri.c \
              ft_strjoin.c \
              ft_strlcat.c \
              ft_strlcpy.c \
              ft_strlen.c \
              ft_strmapi.c \
              ft_strncmp.c \
              ft_strnstr.c \
              ft_strrchr.c \
              ft_substr.c \
              ft_strtrim.c

TO_SRCS     = ft_atoi.c \
              ft_itoa.c \
              ft_tolower.c \
              ft_toupper.c

LST_SRCS    = ft_lstadd_back.c \
              ft_lstadd_front.c \
              ft_lstclear.c \
              ft_lstdelone.c \
              ft_lstiter.c \
              ft_lstlast.c \
              ft_lstmap.c \
              ft_lstnew.c \
              ft_lstsize.c

# --- PATHS & OBJECTS ---
VPATH       = $(addprefix $(SRC_DIR), $(SUBDIRS))

SRCS        = $(IS_SRCS) $(MEM_SRCS) $(PUT_SRCS) $(STR_SRCS) $(TO_SRCS)
OBJS        = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
BONUS_OBJS  = $(addprefix $(OBJ_DIR), $(LST_SRCS:.c=.o))

# --- RULES ---

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "✓ Libft compiled"

bonus: .bonus

.bonus: $(OBJS) $(BONUS_OBJS)
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
	@touch .bonus
	@echo "✓ Libft with Bonus compiled"

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR) .bonus
	@echo "✗ Libft objects removed"

fclean: clean
	@$(RM) $(NAME)
	@echo "✗ libft.a removed"

re: fclean all

.PHONY: all clean fclean re bonusclear
