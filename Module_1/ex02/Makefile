SRCS = main.cpp\

OBJS = $(SRCS:.cpp=.o)
NAME = brain
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++
RM = rm -f

ifdef DEBUG
	CXXFLAGS += -g -fsanitize=address
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

debug:
	$(CXX) $(CXXFLAGS) -g -fsanitize=address -o $(NAME) $(SRCS)

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all