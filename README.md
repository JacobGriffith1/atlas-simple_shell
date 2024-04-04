
# C - Simple Shell

A simple command interpreter.
Built by students of Atlas.

## Authors

- [Griffith, Jacob](https://www.github.com/JacobGriffith1)
- [Lockhart, Blythe](https://www.github.com/blythelockhart)

## Installation

Install this project with

```bash
  git clone https://github.com/JacobGriffith1/atlas-simple_shell.git
  cd atlas-simple_shell
```
    
## Deployment

To deploy the shell, run

```bash
./main
```

Once the shell is ready to receive input, the prompt

```bash
:) 
```

will print to stdout.

## Usage

Once the prompt has been displayed, the shell will receive and interpret user input. In addition to functions defined in the following headers;

- <stdio.h>
- <stdlib.h>
- <string.h>
- <sys/types.h>
- <sys/wait.h>
- <unistd.h>

the shell also includes the following built in functions;

- ss_cd - Used to change directories within the shell
- ss_exit - Used to exit the shell
- ss_help - Used to display a list of built-ins, along with a description of how to execute them.


## Acknowledgements

The following articles were instrumental in helping the authors build this shell.

 - [Stephen Brennan - Write a Shell in C](https://brennan.io/2015/01/16/write-a-shell-in-c/)
 - [Nyangaresibrian - Simple Shell](https://medium.com/@nyangaresibrian/simple-shell-b7014425601f)

