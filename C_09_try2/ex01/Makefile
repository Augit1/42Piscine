CC := gcc
CFLAGS := -Wall -Wextra -Werror

SRC_DIR := srcs
INC_DIR := includes

SRCS := $(SRC_DIR)/ft_putchar.c $(SRC_DIR)/ft_swap.c $(SRC_DIR)/ft_putstr.c $(SRC_DIR)/ft_strlen.c $(SRC_DIR)/ft_strcmp.c
OBJS := $(SRCS:.c=.o)

LIB := libft.a
HEADER := $(INC_DIR)/ft.h

.PHONY: all clean fclean re

all: $(LIB)

$(LIB): $(OBJS)
	@ar rcs $(LIB) $(OBJS)
	@echo "Library $(LIB) created."

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
	@echo "Compiling $<"

clean :
	@$(RM) $(OBJS)
	@echo "Object files removed."

fclean : clean
	@$(RM) $(LIB)
	@echo "Library $(LIB) removed."

re : fclean all
