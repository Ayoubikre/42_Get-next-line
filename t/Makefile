CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS1 = $(shell find . -iname "*.c" -type f)
OBJS = $(SRCS1:.c=.o)

NAME = a

all: $(NAME) c

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS)  $(OBJS) -o $(NAME)
	./$(NAME)

c:
	@rm -rf $(OBJS) 

fc: c
	@rm -rf $(NAME) 

re: fc all

