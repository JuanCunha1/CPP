NAME = program
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I./include -fsanitize=address -MMD -MP
RM = rm -rf

SRC_DIR = src

SRCS =	$(SRC_DIR)/main.cpp \
		$(SRC_DIR)/FragTrap.cpp

OBJ_DIR = obj
OBJ = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEP = $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ) Makefile
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEP)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: all clean
	./$(NAME)

.PHONY: all clean fclean re run
