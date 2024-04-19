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
<<<<<<< HEAD
	int num_tokens = 0, i; /* Initialize counters of tokens */
	char *lineptr_copy = strdup(lineptr); /* Copy of the command to */
	/* avoid modifying the original and keep the original */
=======
	int num_tokens = 0, i; /* Initialize counters */
	char *lineptr_copy = strdup(lineptr); /* Copy of the command to */
	/* avoid modifying the original and modifying the original */
>>>>>>> 0dd9a810f9779719469066be5a4649b4ab70c39a
	if (lineptr_copy == NULL) /* Check if memory allocation for copy failed */
		exit(98);

/* Count the number of tokens in the command */
	token = strtok(lineptr_copy, delim); /* Tokenize the command */
	while (token != NULL) /* Iterate through each token */
	{
		num_tokens++; /* Increment token count */
		token = strtok(NULL, delim); /* Move to the next token */
	}
<<<<<<< HEAD
=======

>>>>>>> 0dd9a810f9779719469066be5a4649b4ab70c39a
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
		argv[i] = malloc(sizeof(char) * (strlen(token) + 1));
/* Allocate memory for token */
		strcpy(argv[i], token); /* Copy token into array */
		token = strtok(NULL, delim); /* Move to the next token */
	}
	argv[i] = NULL; /* Set the last element of the array to */
/* NULL to indicate end of tokens */
	free(lineptr_copy); /* Free allocated memory for the copy */
<<<<<<< HEAD
	return (argv); /* Return the array of tokens */
=======
	return (argv); /* Return array of tokens */
>>>>>>> 0dd9a810f9779719469066be5a4649b4ab70c39a
}
