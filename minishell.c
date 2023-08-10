/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:18:00 by armgevor          #+#    #+#             */
/*   Updated: 2023/07/05 13:18:02 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ctrl_c_handleing(int signal)
{
	(void)signal;
	// if (signal == SIGINT)
	// rl_on_new_line();
	printf("bareeeeev");
	rl_on_new_line();
	rl_redisplay();
	exit (0);
}

void ctrl_d_handleing(int sig)
{
	(void)sig;
	exit (0);
}

int main(int c, char **v, char **envp)
{
	(void)c, (void)v;
	char *str;

	// int i = 5;
	(void)envp;
	// clear_history();
	signal(SIGINT, ctrl_c_handleing);
	while(1)
	{
		// signal(EOF, ctrl_d_handleing);
		str = readline("minishell armgevor$ ");
		if (!str)
		{
			printf("\nexit\n");
			exit(0);
		}
		
		// printf("%s\n", str);
		ft_pwd(str);
		

		if(!ft_strncmp(str, "echo", 4))
			ft_echo(c, str + 5);
		add_history(str);
		
		rl_on_new_line();
		rl_redisplay();
		free(str);
	}
	// for (int i = 0; envp[i]; i++)
	// 	printf("%s\n\n\n", envp[i]);
	
	return 0;
}
