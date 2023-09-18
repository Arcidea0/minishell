/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <armgevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:18:00 by armgevor          #+#    #+#             */
/*   Updated: 2023/09/15 16:53:23 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ctrl_c_handleing(int signal)
{
	(void)signal;
	// rl_replace_line("minishell armgevor$ ", 0);
	rl_on_new_line();
	rl_redisplay();
	exit (0);
}
