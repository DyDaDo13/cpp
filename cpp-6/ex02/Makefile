CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp A.cpp B.cpp C.cpp Base.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = identify

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