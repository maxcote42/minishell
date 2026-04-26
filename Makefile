# --------------------------
# VARIABLES PRINCIPALES
# --------------------------
NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror -I/opt/homebrew/opt/readline/include
LDFLAGS = -L/opt/homebrew/opt/readline/lib -lreadline

# SOURCES DU MINISHELL
SRC = main.c \
      utils.c \
      lexer/lexer.c \
      lexer/lexer_utils.c \
      parser/parser.c \
      parser/parser_utils.c \
      parser/parser_utils2.c \
      parser/expand.c \
	parser/expand_utils.c \
      parser/environment.c \
      signals/signals.c \
      exec/exec_main.c \
      exec/exec_pipeline.c \
      exec/exec_env.c \
      exec/cleanup.c \
      exec/init.c \
      exec/exec_utils.c \
      exec/heredoc.c \
      exec/heredoc_utils.c \
      exec/heredoc_utils2.c \
      exec/exec_cmd/exec_cmd.c \
      exec/exec_cmd/find_cmd.c \
      exec/exec_cmd/redirs_cmd.c \
      exec/builtins/builtins.c \
      exec/builtins/cd.c \
      exec/builtins/echo.c \
      exec/builtins/env.c \
      exec/builtins/exit.c \
      exec/builtins/export.c \
      exec/builtins/pwd.c \
      exec/builtins/unset.c

OBJ_DIR = objects
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	@echo "=== Building libft ==="
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re