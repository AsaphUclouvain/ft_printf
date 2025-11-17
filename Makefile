NAME = libftprintf.a
LIBFT = libft/
SRC_DIR = src/
OBJ_DIR = obj/
CC = cc
INCLUDE = include
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDE)
AR = ar rcs
RM = rm -rf

SRC_FILES = attributes_extractor2 ft_printf handle_integer handle_unsigned_int \
	attributes_extractor3 generic_converter handle_percent string_builder utils \
	attributes_extractor handle_char handle_pointer string_builder_utils width_and_padding \
	ft_itoa_base handle_hex handle_string

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
LIBFT_FILES =  ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint \
	ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove \
	ft_strlcpy ft_strlcat ft_toupper ft_tolower ft_strchr \
	ft_strrchr ft_strncmp ft_memchr ft_memcmp ft_strnstr \
	ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin \
	ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri \
	ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd

LIBFT_OBJ = $(addprefix $(LIBFT), $(addsuffix .o, $(LIBFT_FILES)))
HEADER = $(INCLUDE)/ft_printf.h $(INCLUDE)/libft.h

all : $(NAME)

bonus : all

$(NAME) : $(OBJ)
	@make -C $(LIBFT)
	@$(AR) $(NAME) $(OBJ) $(LIBFT_OBJ)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ_DIR)
	@make clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT)

re : fclean all

.PHONY : all clean fclean re bonus
