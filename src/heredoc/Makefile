NAME = a.out

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

INC_DIR = ../../headers
LIBFT_INC = ../../libft/includes
IFLAGS = -I$(INC_DIR) -I$(LIBFT_INC)

LIBFT_DIR = ../../libft
LIBFT_A = $(LIBFT_DIR)/libft.a

MYLIB_A = libmylib.a

SOURCES := $(wildcard *.c)
OBJECTS := $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_A) $(MYLIB_A)
	$(CC) $(CFLAGS) $(IFLAGS) \
		$(OBJECTS) $(MYLIB_A) $(LIBFT_A) \
		-lreadline -o $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR) all

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
