CC = c++
CFLAGS = -Wall -Wextra -std=c++98 -pedantic

SRCS = main.cpp Harl.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = Harlfilter

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