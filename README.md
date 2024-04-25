## SIMPLE SHEL WITCH HOLBERTON SCHOOL BDX
## DESCRIPTION OF THE PROJECT
Simple Shell is a basic interactive shell program written in C. It provides a command-line interface where users can execute various system commands and basic shell functionalities.

## Features
- Executes system commands
- Supports basic built-in commands like `cd`, `pwd`, and `exit`
- Provides a simple command-line interface
- Supports syntax similar to other Unix-like shells

## Getting Started
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
## REQUIREMENTS
- You're permitted to use vi, vim, or emacs as text editors.
- Your files will be compiled on Ubuntu 20.04 LTS using gcc with the following options: -Wall -Werror -Wextra -pedantic -std=gnu89.
- You must include a README.md file at the root of the project folder.
- Your code should adhere to the Betty style, which will be checked using betty-style.pl and betty-doc.pl.
- Each file should contain no more than 5 functions.
    
## DETAILED QUESTIONS

- Write a README
- Write a man for your shell.
- You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker
- Write a beautiful code that passes the Betty checks
- Write a UNIX command line interpreter.
- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
- The prompt is displayed again each time a command has been executed.
- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
- The command lines are made only of one word. No arguments will be passed to programs.
- If an executable cannot be found, print an error message and display the prompt again.
- Handle errors.
- You have to handle the “end of file” condition (Ctrl+D)

You don’t have to:

- use the PATH
- implement built-ins
- handle special characters : ", ', `, \, *, &, #
- be able to move the cursor
- handle commands with arguments

## BASIC SHELL COMMANDS
Here are some of the main commands you can use in the Simple Shell:

| Command    | Description                                          |
|------------|------------------------------------------------------|
| `cd`       | Change directory                                     |
| `pwd`      | Print working directory                             |
| `ls`       | List directory contents                             |
| `mkdir`    | Make directories                                    |
| `rm`       | Remove files or directories                         |
| `cp`       | Copy files or directories                           |
| `mv`       | Move files or directories                           |
| `touch`    | Create empty files                                   |
| `cat`      | Concatenate and display file content                 |
| `echo`     | Display text or environment variables               |
| `chmod`    | Change file permissions                             |
| `chown`    | Change file ownership                               |
| `chmod`    | Change file permissions                             |



## FLOWCHART
Here's the flowchart


![Diagram Simple_Shell(2)](https://github.com/hziri54/holbertonschool-simple_shell/assets/153849907/d99e868d-29ed-4d66-80f0-b58887e8453e)



## AUTORS
Ziri Houamdi <zirihouamdi64@gmail.com>

Kévin Guédon <kevinguedon2601@gmail.com># holbertonschool-simple_shell
