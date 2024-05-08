CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp ScalarConverter.cpp	
OBJS = $(SRCS:.cpp=.o)
EXEC = converter

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re