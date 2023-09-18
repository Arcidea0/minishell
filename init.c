#include "minishell.h"

void	init(com *msh)
{
	msh->str = NULL;
	msh->sign = NULL;
	msh->next = NULL;
	msh->prev = NULL;
}
