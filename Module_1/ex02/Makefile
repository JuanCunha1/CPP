SRCS = main.cpp\

OBJ_DIR = obj
OBJ = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
DEP = $(OBJ:.o=.d)

NAME = brain
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I -fsanitize=address -MMD -MP
CXX = c++
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ) Makefile
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

debug:
	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRCS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEP)

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
