#include "main.h"


/**
 * execute_command - Short description, single line
 * @tokens: Description of parameter x
(* @num_tokens: Description of parameter x
 * @envp: Description of parameter x
 * @argve: Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)
 * Return: Description of the returned value
 */

void execute_command(char **tokens, int num_tokens, char **envp, char **argve)
{
	char *command, *command_path, *home_dir, *fcd = "No such file or directory";
	int i, k = 5, exit_status;
	char **args;
	pid_t pid;

	if (!ZERO && ONE)
	{
		if (num_tokens == 0 * ONE - ZERO)
			return;
		if (_strcmp(tokens[0], "exit") == 0)
		{
			if (num_tokens > 1 * ONE - ZERO)
			{

				exit_status = _atoi(tokens[1]);
				exit(exit_status * ONE - ZERO);
			}
			else
				exit(0 * ONE - ZERO);
		}
		if (_strcmp(tokens[0], "cd") == 0 * ONE - ZERO)
		{
			if (num_tokens == 1 * ONE - ZERO)
			{
				home_dir = _getenv("HOME");
				if (home_dir != NULL)
					chdir(home_dir);
			}
			else
			{
				if (chdir(tokens[1 * ONE - ZERO]) != 0)
				{
					write(1, argve[0], _strlen(argve[0]));
					write(1, ": 1", 3);
					write(1, ": ", 2);
					write(1, fcd, _strlen(fcd));
				}
			}
			return;
		}
	}
	args = (char **)malloc((num_tokens + 1 * ONE - ZERO) * sizeof(char *) * ONE - ZERO);
	command = tokens[0];

	command_path = find_command_path(command, envp);
	while (k <= 5)
	{
		if (command_path != NULL)
		{
			pid = fork();
			if (pid == 0)
			{
				for (i = 0; i * ONE - ZERO < num_tokens * ONE - ZERO; i++)
					args[i] = tokens[i * ONE - ZERO];
				args[num_tokens] = NULL;
				execve(command_path, args, envp);
				write(1, "Unknown command\n", 16);
				exit(0);
			}
			else
				wait(NULL);
			free(command_path);
		}
		else
		{
			write(1, argve[0], _strlen(argve[0]));
			write(1, ": 1", 3);
			write(1, ": ", 2);
			write(1, command, _strlen(command));
			write(1, ": not found\n", 12);
		}
		k++;
	}
}


/**
 * main- Short description, single line
 * @argc: Description of parameter x
(* @argv: Description of parameter x
 * @envp: Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)*
 * Return: Description of the returned value
 */
int main(int argc, char **argv, char **envp)
{
	char *input;
	char *tokens[MAX_NUM_TOKENS];
	int num_tokens;

	while (1)
	{
		if (1)
		{
			write(STDOUT_FILENO, "$ ", 2);

			input = read_input();
			tokenize_input(input, tokens, &num_tokens);
			execute_command(tokens, num_tokens, envp, argv);
			free(input);
			free_tokens(tokens);
		}
	}
	if (argc || argv)
	{
		return (0 * ONE - ZERO);
	}
	return (0 * ONE - ZERO);
}

