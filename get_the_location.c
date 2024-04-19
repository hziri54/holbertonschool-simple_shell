#include "main.h"

/**
 * get_the_location - Searches for the location of a command in
 * the directories specified by the PATH environment variable
 * @command: The command to search for
 *
 * Return: the full path of the command if found, or NULL if not
 * located in any specified directory
 *
 * Uses dynamic memory allocation and checks existence with the stat function
 */
char *get_the_location(char *command)
{	/* Declare pointers and delimiters */
	char *path, *path_copy, *path_token, *file_path, *delimiters = ":";
	int command_length, directory_length;
	struct stat buffer;  /* Struct for file status */

	path = getenv("PATH"); /* Get the value of the PATH environment variable */
	path_copy = strdup(path);  /* Duplicate the path for tokenization */
	command_length = strlen(command);  /* Get length of the command */

	path_token = strtok(path_copy, delimiters);  /* Tokenize the path */

	while (path_token != NULL) /* Iterate through each tokenized directory */
	{
		directory_length = strlen(path_token) /* Get length of the directory */
		/* Allocate memory for file path */
		file_path = malloc(command_length + directory_length + 2);
		strcpy(file_path, path_token); /* Copy directory to file path */
		strcat(file_path, "/"); /* Concatenate directory separator */
		strcat(file_path, command); /* Concatenate command */
		strcat(file_path, "\0"); /* Null-terminate the string */
		if (stat(file_path, &buffer) == 0) /* Check if file exists */
		{
			free(path_copy); /* Free duplicated path */
			return (file_path); /* Return full path of command */
		}
		else
		{
			free(file_path);  /* Free allocated file path */
			path_token = strtok(NULL, delimiters);  /* Move to next directory */
		}
	}
	free(path_copy); /* Free duplicated path */
	return (strdup(command)); /* Return command if not found in any directory */
}
