#ifndef MINISHELL_H
#define MINISHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <readline/readline.h> 
#include <readline/history.h>
// #include "libft/libft.h"

#define IN 0
#define OUT 1
#define SPACE 5
#define PIP 6
#define FILD 7		// '
#define EX_FILD 8		// "
#define REDIR_OUT 9	// >
#define REDIR_IN 10	// <
#define REDIR_AP 11	// >> 
#define REDIR_SO 12	// <<
#define WORD 13

int	g_exit;

typedef struct tockens
{
	int		id;
	// int		count;
	int		in;
	int		out;
	// int		redir;
	char	*s;
	struct tockens *next;
	struct tockens *prev;
}toc;

typedef struct command
{
	char			**str;
	char			*sign;
	struct command	*next;
	struct command	*prev;
}com;

void	ft_echo(int c, char *str);
void	ft_pwd(char *str);
void	ctrl_c_handleing(int signal);
int		ft_strchr(const char *str, int b);
int		ft_strncmp(const char *a, const char *b, size_t n);
void	ft_echo(int c, char *str);



void	init(com *msh);
// size_t	ft_strlen(const char *s);
// int		ft_strcmp(const char *a, const char *b);
// int		ft_strncmp(const char *a, const char *b, size_t n);
// char	**ft_split(char const *s, char c);
int		count_words(const char *str, char c);
char	*word_dup(const char *str, int start, int finish);
// char	*ft_strdup(const char *s1);



#endif