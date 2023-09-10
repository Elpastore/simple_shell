This project is about simple_shell
The objectif is to build our own shell that look like
the sh.

Here is how the shell  works:
1. Take an input form the user
2. Parse it and tokenise into token :if we have the new line character it may failure; so remove the \n.
3. Execute the command. The fisrt token is the command and others
represente arguments.

So we will try to build this kind of program.
Important :
Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
	if no error is directed like like command doesn't exit, print (sh: 1: ks: not found) where sh is the name of the program
	1 is the number of run and ks the entry command
The only difference is when you print an error, the name of the program must be equivalent to your argv[0] (See below)
Your shell should work like in interactive mode and non interactive mode.
	In iteractive mode isatty(STDIN_FILENO) return 1.

For interactive mode use  isatty function. It returns 1 if your program interract with the terminal 0 if it's not the case

1. Simple shell 0.1
mandatory
Write a UNIX command line interpreter.

Usage: simple_shell
Your Shell should:

Display a prompt and wait for the user to type a command. A command line always ends with a new line.
	DO it using getline function
	COmmand should be stored into a string to perform after tokenization using strtok.
	THe result of token should be also stored into an array of char.
The prompt is displayed again each time a command has been executed.
	USe a while loop to display the prompt each time
	Execute command using execve() after calling fork()
	
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
The command lines are made only of one word. No arguments will be passed to programs.
	This mean after token; we should just take the first result of token
	Because using strtok, the input will te split into small work called tokens and the first token
	is the command and others tokens are argument.

If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
You have to handle the "end of file" condition (Ctrl+D)
You don't have to:

use the PATH
implement built-ins
handle special characters : ", ', `, \, *, &, #
be able to move the cursor
handle commands with arguments
execve will be the core part of your Shell, don't forget to pass the environ to it
