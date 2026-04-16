SRCS = main.cpp Zombie.cpp zombieHorde.cpp\

NAME = zombie

OBJ_DIR = obj
OBJ = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
DEP = $(OBJ:.o=.d)

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I -fsanitize=address -MMD -MP
CXX = c++
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ) Makefile
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEP)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
