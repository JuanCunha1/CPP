SRCS = Account.cpp tests.cpp\

OBJS = $(SRCS:.cpp=.o)
NAME = bank
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I. -MMD -MP
CXX = c++
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) Makefile
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

debug:
	$(CXX) $(CXXFLAGS) -g -fsanitize=address  -o $(NAME) $(SRCS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(OBJS:.o=.d)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS:.o=.d)

fclean: clean
	$(RM) $(NAME)

re: fclean all
