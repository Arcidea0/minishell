#include "minishell.h"

void	ft_pwd(char *str)
{
	char cwd[1024];

	if (!ft_strncmp(str, "pwd ", 4) || !ft_strncmp(str, "pwd\0", 4))
	{
		if (getcwd(cwd, sizeof(cwd)) != NULL)
			printf("%s\n", cwd);
		else
			perror("getcwd");
	}
}