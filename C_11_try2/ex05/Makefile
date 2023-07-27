CC := gcc
CFLAGS := -Wall -Wextra -Werror
SRC_DIR := src
INC_DIR := includes

SRCS := $(SRC_DIR)/func.c $(SRC_DIR)/main.c $(SRC_DIR)/operatorfunc.c
OBJS := $(SRCS:%.c=%.o)
HEADERS := $(INC_DIR)/func.h $(INC_DIR)/main.h $(INC_DIR)/operatorfunc.h

TARGET := do-op

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJS)
	@$(CC) $(CFLAGS) -I$(INC_DIR) $(OBJS) -o $(TARGET)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(TARGET)

re: fclean all
