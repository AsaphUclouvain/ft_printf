NAME = libftprintf.a
LIBFT = libft
SRC_DIR = src/
OBJ_DIR = obj/
CC = cc
CFLAGS = -Wall -Werror -Wextra -I
INCLUDE = include
AR = ar rcs
RM = rm -rf

SRC_FILES = attributes_extractor2 ft_printf handle_integer handle_unsigned_int \
	attributes_extractor3 generic_converter handle_percent string_builder utils \
	attributes_extractor handle_char handle_pointer string_builder_utils width_and_padding \
	ft_itoa_base handle_hex handle_string

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@$(AR) $(NAME) $^

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
	$(RM) $(OBJ_DIR)
	@make clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT)

re : 
	fclean all

.PHONY : all clean fclean re
