NAME = libmylib.a

CC = gcc
AR = ar
ARFLAGS = rcs

CFLAGS = -Wall -Wextra -Werror -g

INC_DIR = ../../includes
LIBFT_INC = ../../libft/includes
IFLAGS = -I$(INC_DIR) -I$(LIBFT_INC)

LIBFT_DIR = ../../libft
LIBFT_A = $(LIBFT_DIR)/libft.a

SOURCES := $(wildcard *.c)
OBJECTS := $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_A)
	cp $(LIBFT_A) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)

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
