/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <armgevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:18:00 by armgevor          #+#    #+#             */
/*   Updated: 2023/09/15 18:28:52 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

toc	*create_tocken5(char **str)
{
	toc *node;
	
	node = malloc(sizeof(toc));
	if (!node)
		return (0)
	node->s = malloc(2 * sizeof(char));
	if (!node->s)
		return (0);
	node->s = " ";
	node->in = 0;
	node->out = 1;
	node->prev = NULL;
	node->next = NULL;
	*str++;
}

toc	*create_tocken6(char **str)
{
	toc *node;
	
	node = malloc(sizeof(toc));
	if (!node)
		return (0)
	node->s = malloc(2 * sizeof(char));
	if (!node->s)
		return (0);
	node->s = "|";
	node->in = 0;
	node->out = 1;
	node->prev = NULL;
	node->next = NULL;
	*str++;
}

toc	*create_tocken7(char **str)
{
	toc *node;
	
	node = malloc(sizeof(toc));
	if (!node)
		return (0)
	node->s = malloc(2 * sizeof(char));
	if (!node->s)
		return (0);
	node->s = "\"";
	node->in = 0;
	node->out = 1;
	node->prev = NULL;
	node->next = NULL;
	*str++;
}

toc	*create_tocken8(char **str)
{
	toc *node;
	
	node = malloc(sizeof(toc));
	if (!node)
		return (0)
	node->s = malloc(2 * sizeof(char));
	if (!node->s)
		return (0);
	node->s = "\'";
	node->in = 0;
	node->out = 1;
	node->prev = NULL;
	node->next = NULL;
	*str++;
}


toc	*create_tocken9(char **str)
{
	toc *node;
	
	node = malloc(sizeof(toc));
	if (*(str + 1) == '>')
	{
		node->id = 11;
		str++;
		node->s = malloc(3 * sizeof(char));
		node->s = ">>";
	}
	else
	{
		node->s = malloc(2 * sizeof(char));
		node->s = ">";
	}
	node->in = 0;
	node->out = 1;
	node->prev = NULL;
	node->next = NULL;
	*str++;
}

toc	*create_tocken10(char **str)
{
	toc *node;
	
	node = malloc(sizeof(toc));
	if (*(str + 1) == '<')
	{
		node->id = 11;
		str++;
		node->s = malloc(3 * sizeof(char));
		node->s = "<<";
	}
	else
	{
		node->s = malloc(2 * sizeof(char));
		node->s = "<";
	}
	node->in = 0;
	node->out = 1;
	node->prev = NULL;
	node->next = NULL;
	*str++;
}

toc	*create_tocken13(char **str)
{
	toc *node;
	char *skizb;
	int i;

	node = malloc(sizeof(toc));
	if (!node)
		return (0)
	skizb = *str;
	i = 1;
	while (str && *str && ((*str >= 65 && *str <= 90)
		|| (*str >= 97 && *str <= 122) || (*str >= 48 && *str <= 57)))
	{
		*str++;
		i++;
	}
	node->s = malloc(i * sizeof(char));
	if (!node->s)
		return (0);
	while (--i)
		node->s[i] = skizb[i];
	node->s = "|";
	node->in = 0;
	node->out = 1;
	node->prev = NULL;
	node->next = NULL;
}

toc	*create_tocken1(char **str)
{
	if (*str == '|')
		return create_tocken6(str);
	else if (*str == '>')
		return create_tocken9(str); //done
	else if (*str == '<')
		return create_tocken10(str);
	else if (*str == '\'')
		return create_tocken7(str);
	else if (*str == '\"')
		return create_tocken8(str);
	else if (*str == ' ')
		return create_tocken5(str);
	else if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z') || (*str >= '0' && *str <= '9'))
		return create_tocken13(str);
	else
		exit(1);
}

void	tocken(char **str, toc **tockens)
{
	int	i;
	toc *tmp;

	i = 0;
	tmp = NULL;
	while (str)
	{
		(*tockens)->prev = tmp;
		tmp = create_tocken(str);
		*tockens = tmp;
		// (*tockens)->next = tmp->next;
	}
}

void	error(char *s, int i)
{
	printf("%s\n", s);
	exit(i);
}

int main(int c, char **v, char **envp)
{
	(void)c, (void)v, (void)envp;
	
	char *str, *srgn;
	toc *tockens;
	// char **split;
	// com	msh;

	if (c != 1)
		error("Error: invalid argument.", 1);
	signal(SIGINT, ctrl_c_handleing);
	while(1)
	{
		srgn = readline("hellot hell$ ");
		if (!srgn)
		{
			printf("exit\n");
			exit(0);
		}
		str = srgn;
		tocken(str);
		add_history(srgn);
		free(srgn);
	}
	
	
	return 0;
}


// printf("i am grut\n");