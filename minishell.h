#ifndef MINISHELL_H
#define MINISHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h> 
#include <readline/history.h>





void	ft_echo(int c, char *str);
void	ft_pwd(char *str);




size_t	ft_strlen(const char *s);
int	ft_strcmp(const char *a, const char *b);
int	ft_strncmp(const char *a, const char *b, size_t n);

#endif