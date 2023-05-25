#include "main.h"

/**
 * builtins_list- Short description, single line
 * @list_tokens: Description of parameter x
(* @envp: Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)*
 * Return: Description of the returned value
 */
int builtins_list(char **list_tokens, char **envp)
{
	int iterator;
	char enp[] = "env";

	builtins options[] = {
		{"exit", builtin_exit},
		 {"env", builtin_env},
		  {NULL, NULL}
	};

	for (iterator = 0; options[iterator].builtin != NULL; iterator++)
	{
		if (_strcmp(options[iterator].builtin, list_tokens[0], 0))
		{
			if (_strcmp(options[iterator].builtin, enp, 0))
			{
				return (options[iterator].function(envp));
			}
			else
				return (options[iterator].function(list_tokens));
		}
	}
	return (-1);
}
/**
 * execute- Short description, single line
 * @LT: Description of parameter x
(* @list_tokens: Description of parameter x
 * @en: Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)*
 * Return: Description of the returned value
 */
int execute(char **list_tokens, char **LT, char **en)
{
	pid_t pid;
	char *spp[] = {"ls", NULL};
	char *first = strtok(LT[0], " \n");
	int stat, size = getStringListLength(list_tokens);

	if (!list_tokens)
		return (0);
	pid = fork();

	if (pid == -1)
		perror("Fork error");
	else if (pid == 0)
	{
		if (size > 1)
		{
			if (execve(commandPath(first), list_tokens, en) == -1)
				perror("Error with execution");
		}
		else
		{
			if (execve(commandPath(first), spp, en) == -1)
				perror("Error with execution");
		}
	}
	else
	{
		if (waitpid(pid, &stat, 0) > 0)
		{
			if (WIFEXITED(stat) && !WEXITSTATUS(stat))
				return (0);
			return (0);
		}
	}
	return (0);
}
/**
 * inf_loop- Short description, single line
 * @envp: Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)
 * Return: Description of the returned value
 */
void inf_loop(char **envp)
{
	char *user_input;
	char **list_tokenss;
	int state;
	char *prompt = "$ ";

	do {
		state = isatty(STDIN_FILENO);

		write(STDOUT_FILENO, prompt, _strlen(prompt));
		user_input = read_user_input();

		if (user_input)
		{
			list_tokenss = parse_user_input(user_input);

			if (builtins_list(list_tokenss, envp) >= 0)
			{
			}
			else
			{
				execute(list_tokenss, list_tokenss, envp);
			}
		}
	} while (state == 1);
}

