NAME=minishell
CC = cc
SRC = minishell.c echo.c libft.c pwd.c init.c signals.c
OBJ=$(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -I readline/readline.h -o $(NAME) -lreadline

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re

# CC = cc
# CFLAGS = -Wall -Wextra -Werror
# NAME = minishell
# SRC_DIR = src
# OBJ_DIR = obj

# SRCS = $(wildcard $(SRC_DIR)/*.c)
# OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# LIBS = -lreadline
# INCLUDES = -I$(shell find ${HOME} -name readline)
# LDFLAGS = -L$(shell find ${HOME} -name readline)

# all: $(NAME)

# $(NAME): $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LIBS) -o $@

# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
# 	@mkdir -p $(OBJ_DIR)
# 	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# clean:
# 	rm -rf $(OBJ_DIR)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re