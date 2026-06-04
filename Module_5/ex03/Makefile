NAME = program
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I./include -MMD -MP
RM = rm -rf

SRC_DIR = src

SRCS =	$(SRC_DIR)/main.cpp \
		$(SRC_DIR)/Intern.cpp \
		$(SRC_DIR)/PresidentialPardonForm.cpp \
		$(SRC_DIR)/RobotomyRequestForm.cpp \
		$(SRC_DIR)/ShrubberyCreationForm.cpp \
		$(SRC_DIR)/AForm.cpp \
		$(SRC_DIR)/Bureaucrat.cpp

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
