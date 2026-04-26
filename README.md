*This project has been created as part of the 42 curriculum by maxcote, sfeijoei.*

# MINISHELL

## DESCRIPTION

The goal of this project is to create a program that **reproduces the behavior of a POSIX-compliant Bash shell**.  
This includes handling command execution, environment variables, redirections, pipes, and signals, while respecting the rules of a 42 school project.

The objective is not to fully reimplement Bash, but to understand how a shell works internally by building a **simplified version from scratch**.

---

## TECHNICAL ASPECT

The minishell is written in C and follows a modular architecture to ensure clarity and maintainability.

Main features implemented:
- Prompt display and user input handling
- Command parsing and tokenization
- Execution of built-in commands (such as `cd`, `echo`, `pwd`, `export`, `unset`, `env`, `exit`)
- Execution of external programs via `fork` and `execve`
- Environment variable management
- Pipes (`|`) handling
- Input and output redirections (`<`, `>`, `>>`, `<<`)
- Signal handling (e.g. `Ctrl+C`, `Ctrl+D`, `Ctrl+\`)

Key concepts used:
- Process creation and management
- File descriptors and redirections
- Parsing and lexical analysis
- Memory management
- Signal handling with `signal` and `sigaction`

---

## INSTRUCTIONS

### HOW TO RUN THE PROJECT

Simply compile the program and run it with:

build commands:
```bash
make
make clean
make fclean
make re
```

```bash
./minishell
```

Note: readline() produces memory leaks that cannot be avoided, use `valgrind --suppressions=readline.supp` to suppress them.


### HOW THE PROJECT WAS MADE

We parsed using a **primary structure t_exec** that allows us to transfer information into the required functions. The structure is initialized to allow for better tracking of variables throughout the execution of Minishell.

## RESOURCES

- A guide on how to start understanding minishell: https://medium.com/@mostafa.omrane/mes-conseils-si-je-devais-recommencer-minishell-a9783c51ba1b)
- How to manage pipes https://www.codequoi.com/pourquoi-je-necris-plus-darticles-sur-les-projets-de-42/
- Basics of Bash posix: https://pubs.opengroup.org/onlinepubs/009604499/utilities/xcu_chap02.html
- Abstract Syntax Tress: https://ruslanspivak.com/lsbasi-part7/
- Our previous projects on Pipex and Minitalk.

Use of AI

AI tools were used to assist with: clarifying the explanation of pipes, process execution and improving documentation readability. It also helped us improving the clarity and fluency of the README in English.

We also benefited greatly from the support of our peers working on Minishell.
