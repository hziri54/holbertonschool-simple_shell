#include "main.h"

/**
 * process_command - divides the arguments and stocks into an array
 * @lineptr: command passed by user
 *
 * Return: an array with token
*/

char **process_command(char *lineptr)
{
	const char *delim = " \n"; /* Delimiter used to tokenize the command */
	char *token, **argv; /* Declaration of variables */
	int num_tokens = 0, i; /* Initialize counters */
	char *lineptr_copy = strdup(lineptr); /* Copy of the command to */
	/* avoid modifying the original and modifying the original */
	if (lineptr_copy == NULL) /* Check if memory allocation for copy failed */
		exit(98);
/* Count the number of tokens in the command */
	token = strtok(lineptr_copy, delim); /* Tokenize the command */
	while (token != NULL) /* Iterate through each token */
	{
		num_tokens++; /* Increment token count */
		token = strtok(NULL, delim); /* Move to the next token */
	}
/* Allocate memory for token array */
	argv = malloc(sizeof(char *) * (num_tokens + 1));
/* Allocate memory for array of tokens */
	if (argv == NULL) /* Check if memory allocation failed */
	{
		perror("memory allocation error"); /* Print error message */
		free(lineptr_copy); /* Free allocated memory for the copy */
		exit(98); /* Exit program with error code */
	}

/*  Store each token in the array */
	token = strtok(lineptr, delim); /* Tokenize the original command */
	for (i = 0; token != NULL; i++) /* Iterate through each token */
	{
		/* Allocate memory for token */
		argv[i] = malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(argv[i], token); /* Copy token into array */
		token = strtok(NULL, delim); /* Move to the next token */
	}
	argv[i] = NULL; /* Set the last element of the array to */
/* NULL to indicate end of tokens */
	free(lineptr_copy); /* Free allocated memory for the copy */
	return (argv); /* Return array of tokens */
}
