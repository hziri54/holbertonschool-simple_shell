#include "main.h"

/**
 * _printlineTyped - function for interactive input in a shell
 *
 * Displays a prompt and reads user data from stdin using fgets
 * Executes the command and prints the line entered in the prompt
 * Exits the shell if fgets returns -1 EOF or an error occurs
 *
 * Return: 0 on success, -1 on shell exit or error
 */

int _printlineTyped(void)
{
	char *prompt = "$ "; /* Define the shell prompt */
	char *lineptr = NULL; /* Pointer to store user input line */
	char **tokens; /* Pointer to store command tokens */
	int status, i; /* Variables for status and loop iteration */

	while (1) /* Infinite loop for shell operation */
	{
		if (isatty(fileno(stdin))) /* Check if stdin is associated with a terminal */
			printf("%s", prompt); /* Print the shell prompt if it's a terminal */
			/* Read user input line */
		if (fgets(lineptr, sizeof(lineptr), stdin) == NULL)
		{
			perror("Error reading input"); /* Print error message if reading fails */
			exit(EXIT_FAILURE); /* Exit the program with failure status */
		}
		if (strcmp(lineptr, "\n") == 0) /* Skip process if input line empty */
			continue; /* Skip to the next iteration if the input line is empty */
		/* Remove newline character from input line */
		if (lineptr[strlen(lineptr) - 1] == '\n')
			lineptr[strlen(lineptr) - 1] = '\0';

		tokens = process_command(lineptr); /* Tokenize the input line */
		status = exit_shell(tokens[0]); /* Check if the command is to */
										/* exit the shell */
		if (status > 0) /* If the exit command is entered */
		{
			for (i = 0; tokens[i]; i++) /* Free memory allocated for tokens */
				free(tokens[i]);
			free(tokens);
			exit(EXIT_SUCCESS); /* Exit the program with success status */
		}
		exec_command(tokens); /* Execute the entered command */

		for (i = 0; tokens[i]; i++) /* Free memory allocated for tokens */
			free(tokens[i]);
		free(tokens);
	}
	return (0);
}

/**
 * exit_shell - command for exiting the shell
 * @command: arguments passed by users
 * Return: 0
*/

int exit_shell(char *command)
{
	if (strcmp(command, "exit") == 0) /* Check if the command is exit */
		return (1); /* Return 1 indicating the exit command was entered */
	return (0); /* Return 0 indicating the exit command was not entered */
}

/**
* printenv - prints the current environment
* @environ: environment variable
*/

void printenv(char **environ)
{
	int i; /* Loop iteration variable */

	for (i = 0; environ[i]; i++)   /* Loop through the environment variables */
		printf("%s\n", environ[i]); /*Print each environment variable */
}
