#include "main.h"

/**
 * printenv - prints the current environment
 * @environ: environment variable
 */

void printenv(char **environ)
{
/* Let's iterate through the environment variables */
int i;

	for (i = 0; environ[i] != NULL; i++)
/* Print each environment variable */
		printf("%s\n", environ[i]);
}

/**
 * _printlineTyped - Basic function for interactive input in a shell.
 * Description: Displays a prompt, reads user input from stdin using getline,
 * and prints the entered line.
 * Exits the shell if getline returns -1 (EOF or an error).
 * Dynamically allocates memory for input and frees it at the end.
 * Return: 0 on success, -1 on shell exit or error.
 */
int _printlineTyped(void)
{
	char *prompt = "$ ";
	char *lineptr = NULL;
	char **tokens;
	size_t n = 0;
	ssize_t nchars_read;
	int status, i = 0;
/* Loop indefinitely to continuously read input lines */
	while (1)
	{ /* Print the prompt if input is from a terminal */
		if (isatty(fileno(stdin)))
			printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin); /* Read a line of input */

		if (nchars_read == -1) /* Handle EOF or error while reading input */
		{
			free(lineptr);
			exit(EXIT_FAILURE);
		}
		if (strcmp(lineptr, "\n") == 0) /* Skip process if input line empty */
			continue;
		if (nchars_read > 0 && lineptr[nchars_read - 1] == '\n')
			lineptr[nchars_read - 1] = '\0';
		tokens = process_command(lineptr); /* Tokenize the input line */
		status = exit_shell(tokens[0]); /* Check if the command is exit */
		if (status > 0)
		{
			free(lineptr); /* Free memory,exit shell if exit command execute */
			for (i = 0; tokens[i]; i++)
				free(tokens[i]);
			free(tokens);
			tokens = NULL;
			exit(EXIT_SUCCESS);
		}
		exec_command(tokens); /* Execute the command */
		for (i = 0; tokens[i]; i++) /* Free memory allocated for tokens */
			free(tokens[i]);
		free(tokens);
		tokens = NULL;
	}
	return (0); /* Return 0 to indicate successful completion */
}
