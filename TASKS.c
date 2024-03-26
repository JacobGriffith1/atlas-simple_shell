/**
 * For the sake of keeping track of completed TASKS, please insert a character
 * in the open parentheses '( )' according to the following definitions-
 * 0 - Work in progress. Use this once substantial content has been added with
 * goals of completing a task.
 * Initial (G, L) - Completed by (lastname). Use once task is complete, but
 * still needs review from collaborating author.
 * 1 - Task complete. Use only once a task is believed to be completed as
 * intended, and only after both authors have checked all related files.
 * X - Assistance needed. Use to indicate that there are issues with 
 * completing a task. Please include a comment within related files describing
 * the nature of the issue. Make sure to change X back to 0 (or initial)
 * when resolved.
 *
 * (0) (G) (L) (1) (X)
 *
 */

/**
 * The following tasks are broken up into sections with a blank line between
 * each of them. Feel free to add prototypes, notes on the section, or any
 * other relevant, important information into these blank sections. Please
 * leave a blank line above and below added content, and your last name,
 * for the sake of clarity.
 */

/**
0. README, man, AUTHORS [mandatory]
( )- Write a "README"
( )- Write a "man" for your shell
( )- You should have an "AUTHORS" file at the root of your repository,
     listing all individuals having contributed content to the repository.
     Format, see 'Docker' (https://github.com/moby/moby/blob/master/AUTHORS)

File: "README.md", "man_1_simple_shell", "AUTHORS"
*/

/**
1. Betty would be proud [mandatory]
( )- Write a beautiful code that passes the Betty checks

GitHub repository: "atlas-simple_shell"
*/

/**
2. Simple shell 0.1 [mandatory]
( )- Write a UNIX command line interpreter
Your shell should:
	( )- Display a prompt and wait for the user to type a command.
	     A command line always ends with a new line.
	( )- The prompt is displayed again each time a command has been
	     executed.
	( )- The command lines are simple, no semicolons, no pipes, no
	     redirections or any other advanced features.
	( )- The command lines are made of only one word. No arguments
	     will be passed to programs.
	( )- If an executable cannot be found, print an error message and
	     display the prompt again.
	( )- Handle errors.
	( )- You have to handle the "end of file" contition (Ctrl+D).

You "DON'T" have to:
- use the PATH
- implement built-ins
- handle special characters: " , ' , ` , \ , * , & , #          "<-- ends spec char list
- be able to move the cursor
- handle command with arguments

"execve" will be the core part of your Shell,
don't forget to pass the environ to it.

GitHub repository: "atlas-simple_shell"
*/

/**
3. Simple shell 0.2 [mandatory]
Simple shell 0.1+
	( )- Handle command lines with arguments

GitHub repository: "atlas-simple_shell"
*/

/**
4. Simple shell 0.3 [mandatory]
Simple shell 0.2 +
	( )- Handle the "PATH"
	( )- "fork" must not be called if the command doesn't exist

GitHub repository: "atlas-simple_shell"
*/

/**
5. Simple shell 0.4 [mandatory]
Simple shell 0.3 +
	( )- Implement the "exit" built-in, that exits the shell
	( )- Usage: "exit"

You "DON'T" have to
- handle any argument to the built-in "exit"

GitHub repository: "atlas-simple_shell"
*/

/**
6. Simple shell 1.0 [mandatory]
Simple shell 0.4 +
	( )- Implement the "env" built-in, that prints the current environment

GitHub repository: "atlas-simple_shell"
*/


