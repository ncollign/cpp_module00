# Nom de l'exécutable
NAME = account

# Fichiers sources
SRCS = Account.cpp tests.cpp
OBJS = $(SRCS:.cpp=.o)

# Compilateur et options
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Règles
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
