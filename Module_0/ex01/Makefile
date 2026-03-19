SRC = Contact.cpp PhoneBook.cpp main.cpp
NAME = phonebook
CC = c++ -Wall -Wextra -Werror -std=c++98

OBJ = $(SRC:.cpp=.o)
HEADERS = Contact.hpp PhoneBook.hpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
