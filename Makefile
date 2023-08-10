NAME=minishell
CC = cc
SRC = minishell.c echo.c libft.c pwd.c
OBJ=$(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -I readline/readline.h -lreadline  -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re
