/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:46:38 by armgevor          #+#    #+#             */
/*   Updated: 2023/08/09 15:46:39 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(int c, char *str)
{
	int	i;
	int	q;

c = 0;
	i = 1;
	q = 0;
	if (!ft_strncmp(str, "-n", 2))
	{
		q = 1;
		i++;
	}
	// while (str)
	// {
		if (q)
		{
			printf("%s\n", str + 3);
			printf("\n");
		}
		else
			printf("%s\n", str);
}
