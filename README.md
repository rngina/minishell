# minishell
minishell project from 42 School London

## Overview
The goal was to create a small version of a [Bash](https://www.gnu.org/software/bash/). The shell can execute multiple commands, support redirection and piping, manage environment variables, and implement several built-in commands. It also handles specific keyboard signals (`ctrl-C`, `ctrl-D`) in interactive mode.

![minishell in work](/minishell.gif)

## Features

### General Functionality

- **Prompt Display:** The shell displays a prompt while waiting for user input.
- **Command History:** The shell maintains a history of executed commands.

### Quoting and Metacharacter Handling

- **Single Quotes (`'`):** Prevents the shell from interpreting metacharacters within the quoted sequence.
- **Double Quotes (`"`):** Prevents the shell from interpreting metacharacters within the quoted sequence, except for the dollar sign (`$`).

### Redirection

- **Input Redirection (`<`):** Redirects input from a file.
- **Output Redirection (`>`):** Redirects output to a file, overwriting the file if it exists.
- **Append Output Redirection (`>>`):** Redirects output to a file, appending to the file if it exists.
- **Heredoc (`<<`):** Reads input until a line containing the specified delimiter is seen (without updating the history).

### Piping

- **Pipes (`|`):** Connects the output of one command to the input of the next command in the pipeline.

### Environment Variable Handling

- **Environment Variables (`$`):** Expands to the value of the variable.
- **Exit Status (`$?`):** Expands to the exit status of the most recently executed foreground pipeline.

### Signal Handling in Interactive Mode

- **`ctrl-C`:** Displays a new prompt on a new line.
- **`ctrl-D`:** Exits the shell.

### Built-in Commands

- **`echo`**: Prints text to the standard output. Supports the `-n` option to omit the trailing newline.
- **`cd`**: Changes the current directory. Supports relative or absolute paths.
- **`pwd`**: Prints the current working directory.
- **`export`**: Sets environment variables.
- **`unset`**: Unsets environment variables.
- **`env`**: Prints the current environment variables.
- **`exit`**: Exits the shell.

## Usage

Clone the repository 
```
git clone https://github.com/rngina/minishell.git
```

Compile the project
```
make
```

Run the executable
```
./minishell
```
