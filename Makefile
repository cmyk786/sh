NAME = minishell
# CC=gcc
# CFLAGS=-Wall -Wextra -Werror -g
CC=cc
CFLAGS=-Wall -Wextra -Werror
INC_DIR = includes
LIBFT_INC = libft/includes
IFLAGS = -I$(INC_DIR) -I$(LIBFT_INC)
LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a
SOURCES := \
src/debug.c \
src/env/env_extract.c \
src/env/env_init.c \
src/env/env_utils.c \
src/env/env_access.c \
src/env/env_exit_status.c \
src/env/env_free.c \
src/ex/get_env.c \
src/ex/exp_1.c \
src/ex/cd.c \
src/ex/exp_2.c \
src/ex/sig.c \
src/ex/exp_ex.c \
src/ex/ex_cmd_child.c \
src/ex/exit.c \
src/ex/unset.c \
src/ex/redir.c \
src/ex/echo.c \
src/ex/builtin.c \
src/ex/ex_pipe.c \
src/ex/pwd.c \
src/ex/env.c \
src/ex/ex.c \
src/ex/exp_3.c \
src/exp/heredoc_exp.c \
src/exp/exp_apply.c \
src/exp/exp_tok_list.c \
src/exp/exp_apply_var.c \
src/exp/exp_tok.c \
src/exp/exp_tok_to_argv.c \
src/exp/exp_tok_type.c \
src/exp/exp_utils.c \
src/exp/exp_tok_detect.c \
src/exp/exp_list.c \
src/exp/exp_init.c \
src/exp/exp.c \
src/exp/exp_free.c \
src/free.c \
src/main.c \
src/parsing/ast.c \
src/parsing/ast_check_type.c \
src/parsing/ast_utils2.c \
src/parsing/ast_free.c \
src/parsing/parsing.c \
src/parsing/ast_parse_pipeline.c \
src/parsing/syntax_err.c \
src/parsing/ast_parse_simple_cmd.c \
src/parsing/ast_parse_heredoc.c \
src/parsing/ast_parse_cmd.c \
src/parsing/ast_new.c \
src/parsing/ast_utils.c \
src/tokenize/tokenize_detect.c \
src/tokenize/tokenize.c \
src/tokenize/tokenize_add_token.c \
src/tokenize/tokenize_init.c \
src/tokenize/tokenize_free.c

all: $(NAME)

OBJECTS = $(SOURCES:.c=.o)

$(NAME) : $(OBJECTS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJECTS) $(LIBFT_A) -lreadline -o $(NAME) 

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR) all

%.o : %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re